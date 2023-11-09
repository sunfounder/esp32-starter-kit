変数
==========
変数はデータ値を格納するために使われるコンテナです。

変数を作成するのは非常に簡単です。名前を付けて値を割り当てるだけです。割り当てる際に変数のデータタイプを指定する必要はありません。なぜなら変数は参照であり、割り当てを通じて異なるデータタイプのオブジェクトにアクセスするからです。

変数名を命名する際は、以下のルールに従う必要があります：

* 変数名には数字、文字、アンダースコアのみを含めることができます
* 変数名の最初の文字は文字またはアンダースコアでなければなりません
* 変数名は大文字と小文字を区別します

変数を作成する
------------------
MicroPythonには変数を宣言するコマンドはありません。変数は初めて値を割り当てたときに作成されます。特定の型宣言を使用する必要はなく、変数を設定した後で型を変更することもできます。

.. code-block:: python

    x = 8       # x is of type int
    x = "lily" # x is now of type str
    print(x)

>>> %Run -c $EDITOR_CONTENT
lily

キャスト
-------------
変数にデータタイプを指定したい場合は、キャストによって行うことができます。

.. code-block:: python

    x = int(5)    # y will be 5
    y = str(5)    # x will be '5'
    z = float(5)  # z will be 5.0
    print(x,y,z)

>>> %Run -c $EDITOR_CONTENT
5 5 5.0

タイプを取得する
-------------------
`type()` 関数を使用して変数のデータタイプを取得することができます。

.. code-block:: python

    x = 5
    y = "hello"
    z = 5.0
    print(type(x),type(y),type(z))

>>> %Run -c $EDITOR_CONTENT
<class 'int'> <class 'str'> <class 'float'>

シングルクォートまたはダブルクォート？
----------------------------------------

MicroPythonでは、シングルクォートまたはダブルクォートを使用して文字列変数を定義できます。

.. code-block:: python

    x = "hello"
    # is the same as
    x = 'hello'

大文字・小文字の区別
---------------------
変数名は大文字と小文字を区別します。

.. code-block:: python

    a = 5
    A = "lily"
    #A will not overwrite a
    print(a, A)

>>> %Run -c $EDITOR_CONTENT
5 lily
