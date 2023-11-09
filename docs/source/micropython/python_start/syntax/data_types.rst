データ型
===========

組み込みデータ型
---------------------
MicroPythonには以下のデータ型があります:

* テキスト型: str
* 数値型: int, float, complex
* シーケンス型: list, tuple, range
* マッピング型: dict
* セット型: set, frozenset
* ブール型: bool
* バイナリ型: bytes, bytearray, memoryview

データ型の取得
-----------------------------
`type()` 関数を使用することで、任意のオブジェクトのデータ型を取得できます:

.. code-block:: python

    a = 6.8
    print(type(a))

>>> %Run -c $EDITOR_CONTENT
<class 'float'>

データ型の設定
----------------------
MicroPythonでは、データ型を特に設定する必要はありません。変数に値を割り当てたときに決定されています。

.. code-block:: python

    x = "welcome"
    y = 45
    z = ["apple", "banana", "cherry"]

    print(type(x))
    print(type(y))
    print(type(z))

>>> %Run -c $EDITOR_CONTENT
<class 'str'>
<class 'int'>
<class 'list'>
>>> 

特定のデータ型の設定
----------------------------------

データ型を指定したい場合は、以下のコンストラクタ関数を使用できます:

.. list-table:: 
    :widths: 25 10
    :header-rows: 1

    *   - 例
        - データ型
    *   - x = int(20)
        - int
    *   - x = float(20.5)
        - float
    *   - x = complex(1j)
        - complex
    *   - x = str("Hello World")
        - str
    *   - x = list(("apple", "banana", "cherry"))
        - list
    *   - x = tuple(("apple", "banana", "cherry"))
        - tuple
    *   - x = range(6)
        - range
    *   - x = dict(name="John", age=36)
        - dict
    *   - x = set(("apple", "banana", "cherry"))
        - set
    *   - x = frozenset(("apple", "banana", "cherry"))
        - frozenset
    *   - x = bool(5)
        - bool
    *   - x = bytes(5)
        - bytes
    *   - x = bytearray(5)
        - bytearray
    *   - x = memoryview(bytes(5))
        - memoryview

いくつかを出力して結果を見ることができます。

.. code-block:: python

    a = float(20.5)
    b = list(("apple", "banana", "cherry"))
    c = bool(5)

    print(a)
    print(b)
    print(c)

>>> %Run -c $EDITOR_CONTENT
20.5
['apple', 'banana', 'cherry']
True
>>> 

型変換
----------------
int(), float(), complex()メソッドを使用して、一つの型から別の型に変換できます:
Pythonでは、コンストラクタ関数を使用してキャスティングを行います:

* int() - 整数リテラル、フロートリテラル（すべての小数を除去する）、または文字列リテラル（文字列が整数を表す場合）から整数を構築します
* float() - 整数リテラル、フロートリテラル、または文字列リテラル（文字列がフロートまたは整数を表す場合）からフロート数を構築します
* str() - 文字列、整数リテラル、フロートリテラルを含む幅広いデータ型から文字列を構築します

.. code-block:: python

    a = float("5")
    b = int(3.7)
    c = str(6.0)

    print(a)
    print(b)
    print(c)

注意: 複素数は他の数値型に変換することはできません。
