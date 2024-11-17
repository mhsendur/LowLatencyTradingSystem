import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

class Backtester:
    def __init__(self, initial_balance=100000):
        self.initial_balance = initial_balance
        self.balance = initial_balance
        self.trade_log = []

    def log_trade(self, symbol, price, volume, trade_type):
        """Log a trade with given details"""
        trade = {
            "symbol": symbol,
            "price": price,
            "volume": volume,
            "trade_type": trade_type,
            "value": price * volume if trade_type == "BUY" else -price * volume
        }
        self.trade_log.append(trade)
        # Adjust balance for BUY/SELL trades
        self.balance += trade["value"]

    def run_backtest(self, data):
        """
        Run backtest on provided data.
        Data should be a DataFrame with columns: ['symbol', 'price', 'volume', 'trade_type']
        """
        for index, row in data.iterrows():
            self.log_trade(row['symbol'], row['price'], row['volume'], row['trade_type'])

    def calculate_metrics(self):
        """Calculate performance metrics like P&L and Sharpe ratio"""
        pnl = self.balance - self.initial_balance
        returns = [trade["value"] for trade in self.trade_log]
        mean_return = np.mean(returns)
        std_return = np.std(returns)
        sharpe_ratio = mean_return / std_return * np.sqrt(len(returns)) if std_return != 0 else 0

        print(f"Final Balance: ${self.balance:.2f}")
        print(f"Total P&L: ${pnl:.2f}")
        print(f"Sharpe Ratio: {sharpe_ratio:.2f}")

    def plot_performance(self):
        """Plot cumulative P&L over time"""
        cumulative_pnl = np.cumsum([trade["value"] for trade in self.trade_log])
        plt.plot(cumulative_pnl)
        plt.title("Cumulative P&L Over Time")
        plt.xlabel("Trades")
        plt.ylabel("Cumulative P&L ($)")
        plt.show()

# Sample usage
if __name__ == "__main__":
    # Mock data generation for backtesting (symbol, price, volume, trade_type)
    mock_data = pd.DataFrame([
        {"symbol": "AAPL", "price": 150.0, "volume": 10, "trade_type": "BUY"},
        {"symbol": "AAPL", "price": 152.0, "volume": 5, "trade_type": "SELL"},
        {"symbol": "GOOG", "price": 1800.0, "volume": 1, "trade_type": "BUY"},
        {"symbol": "TSLA", "price": 650.0, "volume": 2, "trade_type": "SELL"},
        {"symbol": "AMZN", "price": 3200.0, "volume": 1, "trade_type": "BUY"},
        {"symbol": "AAPL", "price": 155.0, "volume": 8, "trade_type": "SELL"}
    ])

    backtester = Backtester()
    backtester.run_backtest(mock_data)
    backtester.calculate_metrics()
    backtester.plot_performance()
