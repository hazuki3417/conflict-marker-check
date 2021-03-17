# 多段makeの実行
# https://boxnos.hatenablog.com/entry/20070110/1168429231

build:
	@make -C ./src build

install:
	@cp ./src/conflict-marker-check /usr/local/bin
	@make message-install


uninstall:
	@rm /usr/local/bin/conflict-marker-check
	@make message-uninstall

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

