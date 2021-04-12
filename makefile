# 多段makeの実行
# https://boxnos.hatenablog.com/entry/20070110/1168429231

# build:
# 	@echo [run] $@;
	
# 	@make -C ./src build

# 	@echo;

install:
	@echo [run] $@;
	
	cp ./build/conflict-marker-check /usr/local/bin

	@make message-install
	@echo;


uninstall:
	@echo [run] $@;
	
	rm /usr/local/bin/conflict-marker-check

	@make message-uninstall
	@echo;

message-install:
	@echo 'Installation completed!'
	@echo ''
	@echo 'Thanks for installing'
	@echo '　　　　∩∩'
	@echo '　　　（´･ω･）'
	@echo '　　 ＿|　⊃／(＿＿_'
	@echo '　／　└-(＿＿＿_／'
	@echo '　￣￣￣￣￣￣￣'

message-uninstall:
	@echo 'Installation completed!'
	@echo ''
	@echo 'Thank you for using. See you'
	@echo ''
	@echo '　　 ⊂⌒／ヽ-、＿_'
	@echo '　／⊂_/＿＿＿＿ ／'
	@echo '　￣￣￣￣￣￣￣'
