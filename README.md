# **Low-Latency Trading System Simulator**

## **Overview**
This project is a **simulated low-latency trading system** designed to replicate the core functionalities of a high-frequency trading engine. The system processes mock market data, handles buy/sell orders, and matches them based on price and time priority. The goal is to optimize latency and provide insights into the performance of a simulated trading system.

The project is entirely simulation-based and does not involve any real financial transactions.

---

## **Features**
- **Mock Data Feed**: Simulates live market data with random prices and volumes for various stock symbols.
- **Order-Matching Engine**: Matches buy and sell orders in an order book with minimal latency.
- **Latency Profiling**: Measures the time taken for key operations to ensure low-latency performance.
- **Backtesting Module**: Simulates trading strategies on historical or synthetic data, calculates profit/loss, and evaluates performance metrics.
- **Data Visualization**: Generates insightful charts to analyze trade performance and system latency.

---

## **Project Structure**

### **C Components**
| File                     | Description                                                                 |
|--------------------------|-----------------------------------------------------------------------------|
| `main.c`                | The main entry point of the program. Coordinates the workflow of the system. |
| `mock_data_feed.c`      | Simulates a live market data feed with random stock prices and volumes.       |
| `order_matching_engine.c` | Handles order matching using an order book. Matches orders by price and time. |
| `latency_profiler.c`    | Measures and reports the latency of the order-matching engine.                |
| `mock_data_feed.h`      | Header file for the mock data feed module.                                    |
| `order_matching_engine.h` | Header file for the order-matching engine.                                  |
| `latency_profiler.h`    | Header file for the latency profiler.                                         |

### **Python Components**
| File              | Description                                                                 |
|-------------------|-----------------------------------------------------------------------------|
| `backtesting.py`  | Simulates trading strategies on historical/simulated data and logs results. |
| `reporting.py`    | Generates charts for analyzing trade performance and latency.               |

---

## **Setup and Compilation**

### **Prerequisites**
- GCC (GNU Compiler Collection)
- Python 3.x with the following libraries:
  - `pandas`
  - `matplotlib`
  - `seaborn`
  - `numpy`

### **Steps**
1. Clone the repository:
   ```bash
   git clone https://github.com/mhsendur/LowLatencyTradingSystem/
   cd LowLatencyTradingSystem
   ```
2. Compile the C program:
   ```bash
   gcc main.c mock_data_feed.c order_matching_engine.c latency_profiler.c -o main
   ```
3. Run the compiled program:
   ```bash
   ./main
   ```

4. (Optional) Use Python modules:
   - Run backtesting:
     ```bash
     python3 backtesting.py
     ```
   - Generate reports:
     ```bash
     python3 reporting.py
     ```

---

## **How It Works**

### **C Program Workflow**
1. **Initialization**:
   - The system initializes resources.
2. **Mock Data Feed**:
   - Generates random stock prices and volumes.
   - Prints the data to simulate a live market feed.
3. **Order Matching**:
   - Processes buy/sell orders in the order book.
   - Matches orders based on price and time priority.
   - Measures the latency of the matching engine.
4. **Shutdown**:
   - Cleans up resources and exits the program.

### **Python Modules**
- **Backtesting**:
  - Simulates trade performance using historical/synthetic data.
  - Logs trades and calculates metrics like profit/loss and Sharpe ratio.
- **Reporting**:
  - Visualizes trade volume distribution, profit/loss, cumulative performance, and system latency.

---

## **Example Output**

### **C Program**
```plaintext
Initializing Low-Latency Trading System Simulator...
System initialized.
Loading mock market data...
Symbol: TSLA, Price: 187.80, Volume: 933
Symbol: MSFT, Price: 332.70, Volume: 739
...

Executing trades on simulated data...
Order added: BUY AAPL at 150.00, volume 100
Order added: SELL AAPL at 149.50, volume 50
Matched 50 shares of AAPL at 149.50
Matched 50 shares of AAPL at 150.00
Order Matching latency: 9 microseconds
Shutting down system.
System resources released.
```

### **Python Backtesting**
```plaintext
Final Balance: $10500.00
Total P&L: $500.00
Sharpe Ratio: 1.25
```

### **Python Reporting**
Generates charts such as:
- **Trade Volume Distribution**
- **Profit/Loss Distribution**
- **Cumulative Profit/Loss**
- **Latency Distribution**
