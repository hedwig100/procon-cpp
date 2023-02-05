
C++で書かれた競技プログラミングのためのライブラリ. 

## セットアップ

```
git clone https://github.com/hedwig100/procon-cpp
cd procon-cpp
python3 -m venv .venv
source venv/bin/activate
pip install -r requirements.txt
python3 snippets_generator.py
```

online-judge-toolでコンテスト中にテストケースを手に入れるためにログインしておく. 

```
oj login https://atcoder.jp/
```

コンテストの準備は次のように行う. もし次のコンテストが `abc001` ならば, 

```
source setup.sh abc001
```