#!/usr/bin/env bash

#
#   *  @file parser.sh
#     
#   *  @brief Configure, build and run units tests. Remove previous leftovers if available before building.
#   
#   *  @usage ./run_parser.sh : clean → configure → build → test → run
#             ./run_parser.sh --build: configure → build → run
#             ./run_parser.sh --clean: clean
#             ./run_parser.sh --clean_build: configure → build → run
#   
#   *  @requirements bash, cmake, make
#

set -Eeuo pipefail


readonly SCRIPT_NAME="$(basename "$0")"
readonly SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
readonly BUILD_DIR="${SCRIPT_DIR}/build"
readonly APP_EXECUTABLE="OrderBook"
readonly SIM_EXECUTABLE="MarketSimulator"
readonly TEST_EXECUTABLE="Testing"

SIM_PID=""


#
#   *  @brief Log the processes of the shell script to the terminal.
#
#
log() {
    printf '[%s] %s\n' "$(date '+%F %T')" "$*"
}


#
#   *  @brief Log the errors of the processes of the shell script to the terminal.
#
#
error() {
    printf '[ERROR] %s\n' "$*" >&2
    exit 1
}


#
#   *  @brief Clean and terminates in case of an error.
#
#
cleanup() {
    if [[ -n "${SIM_PID:-}" ]]; then
        log "Shutting down Simulator (PID: $SIM_PID)..."
        kill "$SIM_PID" 2>/dev/null || true
    fi
}
trap cleanup EXIT INT TERM


#
#   *  @brief Cleans the previous version of the build directory.
#
#
clean() {
    log "Cleaning build directory"
    rm -rf "$BUILD_DIR"
}


#
#   *  @brief Creates a new build folder to configure tests
#
#
configure() {
    log "Configuring project"
    cmake -S "$SCRIPT_DIR" -B "$BUILD_DIR" -DCMAKE_BUILD_TYPE=Release
}


#
#   *  @brief Build the cmake to the configured build directory
#
#
build() {
    log "Building project"
    cmake --build "$BUILD_DIR" --parallel "$(nproc)"
}


#
#   *  @brief Run the generated executable app file.
#
#
run() {
    if [[ ! -f "$BUILD_DIR/$APP_EXECUTABLE" ]] || [[ ! -f "$BUILD_DIR/$SIM_EXECUTABLE" ]]; then
        error "Executables not found. Did the build succeed?"
    fi

    # 2. Start Simulator in Background
    log "Launching Market Simulator..."
    "$BUILD_DIR/$SIM_EXECUTABLE" > /dev/null &
    SIM_PID=$!
    
    # 3. Wait for socket binding
    sleep 0.5
    
    # 4. Run Engine in Foreground
    log "Running Trading Engine..."
    "$BUILD_DIR/$APP_EXECUTABLE"
}


#
#   *  @brief Run the generated executable test file.
#
#
run_test() {
    if [[ -f "$BUILD_DIR/$TEST_EXECUTABLE" ]]; then
        log "Running Test Executable"
        "$BUILD_DIR/$TEST_EXECUTABLE"
    else
        log "No tests found (Testing target missing). Skipping."
    fi
}


#
#   *  @brief Print usage information to the terminal.
#
#
usage() {
    cat <<EOF
Usage: $SCRIPT_NAME [option]

Options:
  --build         Configure, build, and run
  --clean         Clean build directory only
  --clean_build   Clean, configure, build, and run
  --test          Configure, build, and run Tests only
  --help          Show this help
EOF
}


main() {
    case "${1:-default}" in
        default)
            clean
            configure
            build
            run_test
            run
            ;;
        --build)
            configure
            build
            run
            ;;
        --clean)
            clean
            ;;
        --clean_build)
            clean
            configure
            build
            run
            ;;
        --test)
            configure
            build
            run_test
            ;;
        --help|-h)
            usage
            ;;
        *)
            error "Unknown option: $1"
            ;;
    esac
}

main "$@"
