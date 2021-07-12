<p align="center">
   <img src="https://proton-test.bloks.io/img/chains/proton.png" width="200">
</p>

# XPR/USD Price Oracle Smart Contract
**An on-chain option to get the exchange rate of XPR/USD.**

The **xprprice** smart contract lets you know the approximate USD value of your XPR tokens.

You can test the smart contract on the Proton Testnet [**xprprice**](https://proton-test.bloks.io/account/xprprice?loadContract=true&tab=Actions&account=xprprice&scope=xprprice&limit=100) account.

## User Story

@benobi wants to know how much are his XPR tokens worth in USD.

## Actions

| Action            | Description                                               |
| :---------:       | :-----------------------:                                 |
| `usdtoxpr`        | Converts a certain amount of USD to the equivalent on XPR |
| `usdtoxprlog`     | Logs the equivalent in XPR and the rate used              |
| `xprtousd`        | Converts a certain amount of XPR to the equivalent on USD |
| `xprtousdlog`     | Logs the equivalent in USD and the rate used              |
