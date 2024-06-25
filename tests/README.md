# Mandatory
```zsh
$ make retest FILE_PATH=hoge	# ファイルhogeを対象に実行
$ make retest 					# 標準入力を対象に実行
$ make retest BUFFER_SIZE=42	# BUFFER_SIZEを指定（デフォルトでは1024）
$ make tclean
```

# Bonus
```zsh
$ make retest_b FILE_PATH1=hoge FILE_PATH2=fuga FILE_PATH3=piyo	# ファイルhoge, fuga, piyoを対象に実行
$ make retest_b BUFFER_SIZE=42	# BUFFER_SIZEを指定（デフォルトでは1024）
$ make retest_b FD_MAX_COUNT=42	# 同時に開くfdの最大数を指定（デフォルトでは1024）
$ make tclean
```