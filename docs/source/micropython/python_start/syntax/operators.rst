.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

演算子
============
演算子は、変数と値に対して操作を行うために使用されます。

* :ref:`算術演算子`

* :ref:`代入演算子`

* :ref:`比較演算子`

* :ref:`論理演算子`

* :ref:`同一性演算子`

* :ref:`メンバーシップ演算子`

* :ref:`ビット演算子`

算術演算子
----------------------
算術演算子を使用して、一般的な数学的操作を行うことができます。

.. list-table:: 
    :widths: 10 30
    :header-rows: 1

    *   - 演算子
        - 名前
    *   - `+`
        - 足し算
    *   - `-`
        - 引き算
    *   - `*`
        - 掛け算
    *   - `/`
        - 割り算
    *   - `%`
        - 剰余
    *   - `**`
        - 累乗
    *   - `//`
        - 切り捨て除算



.. code-block:: python

    x = 5
    y = 3

    a = x + y
    b = x - y
    c = x * y
    d = x / y
    e = x % y
    f = x ** y
    g = x // y

    print(a)
    print(b)
    print(c)
    print(d)
    print(e)
    print(f)
    print(g)

>>> %Run -c $EDITOR_CONTENT
8
2
15
1.66667
2
125
1
8
2
15
>>> 

代入演算子
---------------------

代入演算子は、変数に値を代入するために使用できます。

.. list-table:: 
    :widths: 10 30 30
    :header-rows: 1

    *   - オペレーター
        - 例
        - と同じ
    *   - `=`
        - a = 6
        - a =6
    *   - `+=`
        - a += 6
        - a = a + 6
    *   - `-=`
        - a -= 6
        - a = a - 6
    *   - `*=`
        - a `*=` 6
        - a = a * 6
    *   - `/=`
        - a /= 6
        - a = a / 6
    *   - `%=`
        - a %= 6
        - a = a % 6
    *   - `**=`
        - a `**=` 6
        - a = a ** 6
    *   - `//=`
        - a //= 6
        - a = a // 6
    *   - `&=`
        - a &= 6
        - a = a & 6
    *   - `|=`
        - a `|=` 6
        - a = a | 6
    *   - `^=`
        - a ^= 6
        - a = a ^ 6
    *   - `>>=`
        - a >>= 6
        - a = a >> 6
    *   - `<<=`
        - a <<= 6
        - a = a << 6



.. code-block:: python

    a = 6

    a *= 6
    print(a)

>>> %Run test.py
36
>>> 

比較演算子
------------------------
比較演算子は 2 つの値を比較するために使用されます。

.. list-table:: 
    :widths: 10 30
    :header-rows: 1

    *   - オペレーター
        - 名前
    *   - ==
        - 等しい
    *   - !=
        - 等しくない
    *   - <
        - より小さい
    *   - >
        - より大きい
    *   - >=
        - 以上
    *   - <=
        - 以下





.. code-block:: python

    a = 6
    b = 8

    print(a>b)

>>> %Run test.py
False
>>> 

**False** を返します。なぜなら、 **a** は **b** より小さいからです。

論理演算子
-----------------------

論理演算子は条件文を組み合わせるために使用されます。

.. list-table:: 
    :widths: 10 30
    :header-rows: 1

    *   - 演算子
        - 説明
    *   - and
        - 両方の文が真であればTrueを返す
    *   - or
        - 一方の文が真であればTrueを返す
    *   - not
        - 結果を反転させ、結果が真であればFalseを返す

.. code-block:: python

    a = 6
    print(a > 2 and a < 8)

>>> %Run -c $EDITOR_CONTENT
True
>>> 

同一性演算子
------------------------

同一性演算子は、オブジェクトが等しいかではなく、実際に同じオブジェクトで、同じメモリ位置にあるかどうかを比較するために使用されます。

.. list-table:: 
    :widths: 10 30
    :header-rows: 1

    *   - 演算子
        - 説明
    *   - is
        - 両方の変数が同じオブジェクトであればTrueを返す
    *   - is not
        - 両方の変数が同じオブジェクトでなければTrueを返す

.. code-block:: python

    a = ["hello", "welcome"]
    b = ["hello", "welcome"]
    c = a

    print(a is c)
    # returns True because z is the same object as x

    print(a is b)
    # returns False because x is not the same object as y, even if they have the same content

    print(a == b)
    # returns True because x is equal to y

>>> %Run -c $EDITOR_CONTENT
True
False
True
>>> 

メンバーシップ演算子
----------------------
メンバーシップ演算子は、シーケンスがオブジェクト内に存在するかどうかをテストするために使用されます。

.. list-table:: 
    :widths: 10 30
    :header-rows: 1

    *   - 演算子
        - 説明
    *   - in
        - 指定された値のシーケンスがオブジェクトに存在する場合はTrueを返す
    *   - not in
        - 指定された値のシーケンスがオブジェクトに存在しない場合はTrueを返す

.. code-block:: python

    a = ["hello", "welcome", "Goodmorning"]

    print("welcome" in a)

>>> %Run -c $EDITOR_CONTENT
True
>>> 


ビット演算子
------------------------

ビット演算子は、（バイナリ）数値を比較するために使用されます。

.. list-table:: 
    :widths: 10 20 50
    :header-rows: 1

    *   - 演算子
        - 名前
        - 説明
    *   - &
        - AND
        - 両方のビットが1の場合、各ビットを1に設定
    *   - |
        - OR
        - 二つのビットのうち一方が1の場合、各ビットを1に設定
    *   - ^
        - XOR
        - 二つのビットのうち一方だけが1の場合、各ビットを1に設定
    *   - ~
        - NOT
        - すべてのビットを反転
    *   - <<
        - ゼロ埋め左シフト
        - 右からゼロを押し込んで左シフトし、最左ビットを落とす
    *   - >>
        - 符号付き右シフト
        - 最左ビットのコピーを左から押し込んで右シフトし、最右ビットを落とす

.. code-block:: python

    num = 2

    print(num & 1)
    print(num | 1)
    print(num << 1)

>>> %Run -c $EDITOR_CONTENT
0
3
4
>>>
