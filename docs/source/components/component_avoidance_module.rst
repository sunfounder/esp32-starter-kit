.. _cpn_avoid:

障害物回避モジュール
===========================================

.. image:: img/IR_Obstacle.png
   :width: 400
   :align: center

* **VCC**: 電源供給, 3.3 ~ 5V DC.
* **GND**: グラウンド
* **OUT**: シグナルピン。通常は高レベルで、障害物が検出されると低レベルとなります。

IR障害物回避モジュールは環境光への適応性が高く、赤外線送信管と受信管のペアを持っています。

送信管は赤外線の周波数を放射し、検出方向に障害物がある場合、赤外線の放射が受信管によって受け取られ、
コンパレータ回路の処理後、インジケータが点灯し、低レベルの信号を出力します。

検出距離はポテンショメータで調整可能で、効果的な距離範囲は2-30cmです。

.. image:: img/IR_module.png
    :width: 600
    :align: center

**例**

* :ref:`ar_ir_obstacle` (Arduinoプロジェクト)
* :ref:`py_ir_obstacle` (MicroPythonプロジェクト)
* :ref:`sh_shooting` (Scratchプロジェクト)
* :ref:`sh_tap_tile` (Scratchプロジェクト)
