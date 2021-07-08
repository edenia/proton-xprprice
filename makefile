build:
	@eosio-cpp -w -I include -o proton-xprprice.wasm -contract=xprprice -abigen src/xprprice.cpp

permission:
	$(eval -include .env)
	@cleos wallet unlock --name $(CONTRACT_ACCOUNT) --password $(CONTRACT_PASSWORD) || echo ""
	@cleos -u $(CONTRACT_NETWORK_API) set account permission $(CONTRACT_ACCOUNT) active --add-code
	@cleos wallet lock --name $(CONTRACT_ACCOUNT)

deploy:
	$(eval -include .env)
	@cleos wallet unlock --name $(CONTRACT_ACCOUNT) --password $(CONTRACT_PASSWORD) || echo ""
	@cleos -u $(CONTRACT_NETWORK_API) set contract $(CONTRACT_ACCOUNT) ./ || echo ""
	@cleos wallet lock --name $(CONTRACT_ACCOUNT)