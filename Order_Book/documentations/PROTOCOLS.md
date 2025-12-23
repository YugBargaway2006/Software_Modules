# Binary Market Data Protocol

The engine accepts UDP datagrams containing packed binary structures. All integers are transmitted in **Big Endian** (Network Byte Order).

## Message Structure
The compiler is forced to pack structures (1-byte alignment) to avoid padding issues.

### 1. Header (Common to all messages)
| Field | Type | Size | Description |
| :--- | :--- | :--- | :--- |
| `msgLength` | `uint16_t` | 2 Bytes | Total size of the message. |
| `msgType` | `uint8_t` | 1 Byte | `1` = New Order, `2` = Trade. |

### 2. New Order Message (Type 1)
| Field | Type | Size | Description |
| :--- | :--- | :--- | :--- |
| `header` | `Header` | 3 Bytes | (See above) |
| `orderID` | `uint32_t` | 4 Bytes | Unique Order Identifier. |
| `price` | `uint32_t` | 4 Bytes | Price in Ticks (Price * 100). |
| `quantity` | `uint32_t` | 4 Bytes | Number of shares. |
| `side` | `char` | 1 Byte | 'B' (Buy) or 'S' (Sell). |

**Total Size:** 16 Bytes per packet.