# WANTDO

1. ライブラリの自動Verify(CI)
    - テストケースはlibrary checkerとかのをお借りしてそれを用いてpush時にverifyする

2. 重複コードの除去
    - たとえばmodintは大量にある(mod,mint,fft), それを一箇所にまとめて, includeして使えるようにしたい
    - それだけだと使い勝手が悪いので(ある1ファイルをコピペするだけでは済まない), 後述のことをしたい

3. snipet
    - includeしたのを含めてsnipetにするものをつくる。

4. コードをきれいにする
    - formatする
    - using namespace std; と #include <bits/stdc++.h>以外はライブラリ中では許さない
