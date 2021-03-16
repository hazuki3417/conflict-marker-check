
install:
	# @cp ./rmcomment /usr/local/bin
	@make message-install


uninstall:
	# @rm /usr/local/bin/rmcomment
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

