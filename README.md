# conflict marker check

# 概要

gitによって生成されたコンフリクトマーカーを検出するコマンド。

# 導入

```sh
# インストール
make install

# アンインストール
make uninstall
```

インストールすると下記ディレクトリにコマンドがインストールされます。

```sh
# macOS
which conflict-marker-check 

/usr/local/bin/conflict-marker-check
```



# 使い方

```sh
conflict-marker-check filePaths...
```

## git hookに組み込む

下記のワンライナーをgit hookを組み込むとコンフリクトマーカーを検出時に処理を強制終了します。

```sh
git status -s | cut -b 4- | xargs conflict-marker-check
```

# コマンド実行時の返り値

コンフリクトマーカーを検出すると、コマンドの実行ステータスは`1`を返します。未検出の場合は`0`を返します。

|コンフリクト|ID|
|---|---|
|検出|1|
|未検出|0|
