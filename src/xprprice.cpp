/*
 *
 * @author  EOSCostaRica.io [ https://eoscostarica.io ]
 *
 * @section DESCRIPTION
 *  Source file for the actions related with the xprprice contract
 *
 *    GitHub:         https://github.com/eoscostarica/proton-xprprice
 *
 */

#include <xprprice.hpp>

ACTION xprprice::usdtoxpr(double usd) {
  double rate = get_current_exchange_rate();
  check(rate > 0, "rate not available");

  asset xpr = asset((usd / rate) * 10000, symbol("XPR", 4));
  SEND_INLINE_ACTION(*this, usdtoxprlog, { {get_self(), name("active")} }, { rate, xpr });
}

ACTION xprprice::usdtoxprlog(double rate, asset xpr) {
  require_auth(get_self());
}

ACTION xprprice::xprtousd(double xpr) {
  double rate = get_current_exchange_rate();
  check(rate > 0, "rate not available");

  double usd = xpr * rate;
  SEND_INLINE_ACTION(*this, xprtousdlog, { {get_self(), name("active")} }, { rate, usd });
}

ACTION xprprice::xprtousdlog(double rate, double usd) {
  require_auth(get_self());
}

double xprprice::get_current_exchange_rate() {
  feeds_table _feeds(name("oracles"), name("oracles").value);
  data_table _data(name("oracles"), name("oracles").value);

  auto 	xpr_btc = _feeds.find(0);
  
  if (xpr_btc == _feeds.end() || xpr_btc->name != "XPR/BTC") {
    return 0;
  }

  auto xpr_btc_fee = _data.find(xpr_btc->index);

  if (xpr_btc_fee == _data.end()) {
    return 0;
  }

  auto 	btc_usdt = _feeds.find(1);
  
  if (btc_usdt == _feeds.end() || btc_usdt->name != "BTC/USDT") {
    return 0;
  }

  auto btc_usdt_fee = _data.find(btc_usdt->index);

  if (btc_usdt_fee == _data.end()) {
    return 0;
  }
  
  return xpr_btc_fee->aggregate.d_double.value() * btc_usdt_fee->aggregate.d_double.value();
}

