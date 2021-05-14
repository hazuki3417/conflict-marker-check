# 概要

gitによって生成されたコンフリクトマーカーを検出するコマンドです。
# 開発環境

規格:c++17

# ビルド・インストール・アンインストール

```sh
cd build

cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr/local 

# ビルド
cmake --build .

# インストール
cmake --install .

# アンインストール
xargs rm -rfv < install_manifest.txt
```

# 使い方

```sh
conflict-marker-check filePath1 filePath2 ...
```

[サンプルスクリプト](examples/sample.sh)の実行結果

```sh
$ cd examples

$ ./sample.sh 
conflict marker detection: sample1.php
line: 5 marker type: head
line: 7 marker type: boundary
line: 9 marker type: tail
line: 16 marker type: head
line: 21 marker type: boundary
line: 26 marker type: tail
conflict marker detection: sample2.js
line: 2 marker type: head
line: 4 marker type: boundary
line: 6 marker type: tail
```
## git hookに組み込む

下記のワンライナーをgit hookを組み込むとコンフリクトマーカー検出時に処理を強制終了します。

```sh
git status -s | cut -b 4- | xargs conflict-marker-check
```

# コマンド実行時の返り値

コンフリクトマーカーの検出・未検出によって、コマンドの実行ステータスが変わります。

|コンフリクト|ID|
|---|---|
|検出|1|
|未検出|0|
