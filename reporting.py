# File: reporting.py

import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

class ReportGenerator:
    def __init__(self, trade_log, latency_log=None):
        """
        Initialize with trade and latency logs.
        trade_log: List of trades with columns ['symbol', 'price', 'volume', 'trade_type', 'value']
        latency_log: List of latency measurements in microseconds (optional)
        """
        self.trade_log = pd.DataFrame(trade_log)
        self.latency_log = latency_log

    def plot_trade_volume_distribution(self):
        """Plot the distribution of trade volumes by symbol"""
        plt.figure(figsize=(10, 6))
        sns.histplot(data=self.trade_log, x="volume", hue="symbol", multiple="stack", kde=True)
        plt.title("Trade Volume Distribution by Symbol")
        plt.xlabel("Volume")
        plt.ylabel("Frequency")
        plt.show()

    def plot_pnl_distribution(self):
        """Plot the distribution of profit and loss per trade"""
        plt.figure(figsize=(10, 6))
        sns.histplot([trade['value'] for trade in self.trade_log.to_dict('records')], kde=True)
        plt.title("Profit/Loss Distribution per Trade")
        plt.xlabel("P&L ($)")
        plt.ylabel("Frequency")
        plt.show()

    def plot_cumulative_pnl(self):
        """Plot cumulative P&L over time"""
        cumulative_pnl = self.trade_log['value'].cumsum()
        plt.figure(figsize=(10, 6))
        plt.plot(cumulative_pnl)
        plt.title("Cumulative P&L Over Time")
        plt.xlabel("Trades")
        plt.ylabel("Cumulative P&L ($)")
        plt.show()

    def plot_latency_distribution(self):
        """Plot the distribution of latency, if available"""
        if self.latency_log is not None:
            plt.figure(figsize=(10, 6))
            sns.histplot(self.latency_log, kde=True)
            plt.title("Latency Distribution")
            plt.xlabel("Latency (microseconds)")
            plt.ylabel("Frequency")
            plt.show()
        else:
            print("Latency log is not available for plotting.")

    def generate_report(self):
        """Generate all reports"""
        print("Generating Trade Volume Distribution...")
        self.plot_trade_volume_distribution()
        
        print("Generating P&L Distribution...")
        self.plot_pnl_distribution()

        print("Generating Cumulative P&L Chart...")
        self.plot_cumulative_pnl()

        if self.latency_log:
            print("Generating Latency Distribution...")
            self.plot_latency_distribution()
        else:
            print("No latency data available to plot.")

# Sample usage
if __name__ == "__main__":
    # Mock trade log data
    trade_log = [
        {"symbol": "AAPL", "price": 150.0, "volume": 10, "trade_type": "BUY", "value": 1500.0},
        {"symbol": "AAPL", "price": 152.0, "volume": 5, "trade_type": "SELL", "value": -760.0},
        {"symbol": "GOOG", "price": 1800.0, "volume": 1, "trade_type": "BUY", "value": 1800.0},
        {"symbol": "TSLA", "price": 650.0, "volume": 2, "trade_type": "SELL", "value": -1300.0},
        {"symbol": "AMZN", "price": 3200.0, "volume": 1, "trade_type": "BUY", "value": 3200.0},
        {"symbol": "AAPL", "price": 155.0, "volume": 8, "trade_type": "SELL", "value": -1240.0}
    ]
    latency_log = [120, 135, 100, 145, 130, 110, 125, 140]  # Mock latency data in microseconds

    report = ReportGenerator(trade_log, latency_log)
    report.generate_report()
