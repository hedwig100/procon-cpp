# procon-cpp

procon-cpp is a library for programming contest.

## Setup 

```
git clone https://github.com/hedwig100/procon_lib 
cd procon_lib
python3 -m venv venv
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
make setup-abc001
```

## Verify 

仮想環境の中で

```
oj-verify run
```

## Check

- long longに収まっているか?
- MODは正しいか?
- HINFは想定の最大より本当に大きいか?
