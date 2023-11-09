Forループ
============

`for` ループは、リストや文字列など、任意の項目のシーケンスをトラバースすることができます。

forループの構文フォーマットは以下の通りです：

.. code-block:: python

    for val in sequence:
        Body of for


ここで、 `val` は各イテレーションでシーケンス内の項目の値を取得する変数です。

ループはシーケンスの最後の項目に到達するまで続きます。本体をコードの残りの部分から分離するためにインデントを使用します。

**forループのフローチャート**

.. image:: img/for_loop.png

.. code-block:: python

    numbers = [1, 2, 3, 4]
    sum = 0

    for val in numbers:
        sum = sum+val
        
    print("The sum is", sum)

>>> %Run -c $EDITOR_CONTENT
The sum is 10

Break文
-------------------------

break文を使えば、全ての項目をループする前にループを停止させることができます：



.. code-block:: python

    numbers = [1, 2, 3, 4]
    sum = 0

    for val in numbers:
        sum = sum+val
        if sum == 6:
            break
    print("The sum is", sum)

>>> %Run -c $EDITOR_CONTENT
The sum is 6

Continue文
--------------------------------------------

`continue` 文を使えば、ループの現在のイテレーションを停止し、次のイテレーションで続行することができます：



.. code-block:: python

    numbers = [1, 2, 3, 4]

    for val in numbers:
        if val == 3:
            continue
        print(val)

>>> %Run -c $EDITOR_CONTENT
1
2
4

range()関数
--------------------------------------------

range()関数を使って一連の数値を生成することができます。range(6)は0から5の間の数値を生成します（6つの数値）。

また、range(start, stop, step_size)として開始、停止、ステップサイズを定義することもできます。指定されていない場合、step_sizeはデフォルトで1になります。

rangeの意味では、オブジェクトは「怠惰」です。なぜなら、オブジェクトを作成しても、それが「含む」すべての数値を生成しないからです。しかし、これはin、len、__getitem__操作をサポートしているため、イテレータではありません。

この関数はすべての値をメモリに格納しません。それは非効率的です。したがって、開始、停止、ステップサイズを覚えておいて、進行中に次の数値を生成します。

この関数にすべての項目を出力させるには、list()関数を使用することができます。



.. code-block:: python

    print(range(6))

    print(list(range(6)))

    print(list(range(2, 6)))

    print(list(range(2, 10, 2)))

>>> %Run -c $EDITOR_CONTENT
range(0, 6)
[0, 1, 2, 3, 4, 5]
[2, 3, 4, 5]
[2, 4, 6, 8]

`range()` を `for` ループ内で使用して数値のシーケンスを繰り返すことができます。len()関数と組み合わせてインデックスを使用してシーケンスをトラバースすることもできます。

.. code-block:: python

    fruits = ['pear', 'apple', 'grape']

    for i in range(len(fruits)):
        print("I like", fruits[i])
        
>>> %Run -c $EDITOR_CONTENT
I like pear
I like apple
I like grape

ForループでのElse
--------------------------------

`for` ループにはオプショナルな `else` ブロックも持たせることができます。ループに使用されるシーケンスの項目が使い果たされた場合、 `else` 部分が実行されます。

`break` キーワードを使用して `for` ループを停止させることができます。この場合、 `else` 部分は無視されます。

したがって、中断が発生しなければ、 `for` ループの `else` 部分が実行されます。

.. code-block:: python

    for val in range(5):
        print(val)
    else:
        print("Finished")

>>> %Run -c $EDITOR_CONTENT
0
1
2
3
4
Finished

ループがbreak文で停止された場合、elseブロックは実行されません。

.. code-block:: python


    for val in range(5):
        if val == 2: break
        print(val)
    else:
        print("Finished")

>>> %Run -c $EDITOR_CONTENT
0
1
