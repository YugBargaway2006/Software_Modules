#include <iostream>
#include <vector>
#include <random>
#include <chrono>


class XorShiftGen {
public:
    uint64_t state = 0x4d595df4d0f33173;  // seed

    inline uint64_t next() {
        uint64_t x = state;
        x ^= x << 13;
        x ^= x >> 7;
        x ^= x << 17;
        return state = x;
    }

    inline int flip() {
        return (int)(next() & 1);
    }
};


void simulate_scenario(XorShiftGen& gen, size_t& win, size_t& loss, int win_stop, int loss_stop, size_t& coin_flips) {
    int market = 0;
    while(true) {
        coin_flips++;
        
        int prob = gen.flip();      // Returns 0 or 1 indicating -1 and 1 motion   
        market += (prob * 2) - 1;

        if(market == 10) {
            win++;
            break;
        } 
        else if(market == -5) {
            loss++;
            break;
        }
    }
}


/**
 * @brief Entrypoint for the complete csv parser.
 */
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    auto start = std::chrono::steady_clock::now();
    std::cout << "Starting Simulation: 0ms" << std::endl;
    
    int simulation_limit = 10000000;
    int win_stop = 10;
    int loss_stop = -5;
    size_t win = 0;
    size_t loss = 0;
    size_t flips = 0;

    XorShiftGen gen;

    for(size_t i = 0; i < simulation_limit; i++) {
        simulate_scenario(gen, win, loss, win_stop, loss_stop, flips);
    }

    double prob_win = (win * 1.0) / simulation_limit;
    double prob_loss = (loss * 1.0) / simulation_limit;

    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds> (end - start);

    std::cout << "Probability: Win  = " << prob_win << std::endl;
    std::cout << "Probability: Loss = " << prob_loss << std::endl;
    std::cout << "Total Time Taken = " << duration.count() << "ms" << std::endl;
    std::cout << "Total Equivalent coin flips = " << flips << " flips" << std::endl;

}