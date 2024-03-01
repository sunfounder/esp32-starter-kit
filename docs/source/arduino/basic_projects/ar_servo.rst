.. _ar_servo:

4.3 Balanceo del Servo
==========================
Un Servo es un tipo de dispositivo basado en posición conocido por su habilidad para mantener ángulos específicos y proporcionar una rotación precisa. Esto lo hace altamente deseable para sistemas de control que demandan ajustes de ángulo consistentes. No es sorprendente que los Servos se hayan utilizado ampliamente en juguetes controlados remotamente de alta gama, desde modelos de aviones hasta réplicas de submarinos y robots controlados a distancia sofisticados.

En esta aventura fascinante, nos desafiaremos a manipular el Servo de una manera única: ¡haciéndolo oscilar! Este proyecto ofrece una oportunidad brillante para profundizar en la dinámica de los Servos, afilando tus habilidades en sistemas de control precisos y ofreciendo una comprensión más profunda de su operación.

¿Estás listo para hacer bailar al Servo al son de tus melodías? ¡Embarquémonos en este emocionante viaje!

**Componentes Necesarios**

Para este proyecto, necesitamos los siguientes componentes.

Definitivamente es conveniente comprar un kit completo, aquí tienes el enlace:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nombre	
        - ELEMENTOS EN ESTE KIT
        - ENLACE
    *   - Kit de Inicio ESP32
        - 320+
        - |link_esp32_starter_kit|

También puedes comprarlos por separado en los enlaces a continuación.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCCIÓN DEL COMPONENTE
        - ENLACE DE COMPRA

    *   - :ref:`cpn_esp32_wroom_32e`
        - |link_esp32_wroom_32e_buy|
    *   - :ref:`cpn_esp32_camera_extension`
        - \-
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_servo`
        - |link_servo_buy|


**Pines Disponibles**

Aquí tienes una lista de pines disponibles en la placa ESP32 para este proyecto.

.. list-table::
    :widths: 5 20 

    * - Pines Disponibles
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


**Esquemático**

.. image:: ../../img/circuit/circuit_4.3_servo.png

**Conexión**

* El cable naranja es de señal y se conecta al IO25.
* El cable rojo es VCC y se conecta a 5V.
* El cable marrón es GND y se conecta a GND.

.. image:: ../../img/wiring/4.3_swinging_servo_bb.png

**Código**

.. note::

    * Abre el archivo ``4.3_servo.ino`` bajo la ruta de ``esp32-starter-kit-main\c\codes\4.3_servo``. O copia este código en **Arduino IDE**.
    * Después de seleccionar la placa (ESP32 Dev Module) y el puerto adecuado, haz clic en el botón **Subir**.
    * :ref:`unknown_com_port`
    * Se utiliza aquí la biblioteca ``ESP32Servo``, puedes instalarla desde el **Gestor de Bibliotecas**.

        .. image:: img/servo_lib.png

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/34c7969e-fee3-413c-9fe7-9d38ca6fb906/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Una vez que hayas subido el código, podrás ver el brazo del servo rotando en el rango de 0°~180°.

**¿Cómo funciona?**

#. Incluir la biblioteca |link_esp32servo|: Esta línea importa la biblioteca ESP32Servo, necesaria para controlar el motor servo.

    .. code-block:: arduino

        #include <ESP32Servo.h>

#. Definir el servo y el pin al que está conectado: Esta sección declara un objeto Servo (``myServo``) y un entero constante (``servoPin``) para representar el pin al que está conectado el motor servo (pin 25).

    .. code-block:: arduino

        // Define the servo and the pin it is connected to
        Servo myServo;
        const int servoPin = 25;

#. Definir los anchos de pulso mínimo y máximo para el servo: Esta sección establece los anchos de pulso mínimo y máximo para el motor servo (0.5 ms y 2.5 ms, respectivamente).

    .. code-block:: arduino

        // Define the minimum and maximum pulse widths for the servo
        const int minPulseWidth = 500; // 0.5 ms
        const int maxPulseWidth = 2500; // 2.5 ms

#. La función ``setup`` inicializa el motor servo adjuntándolo al pin especificado y configurando su rango de anchura de pulso. También establece la frecuencia PWM para el servo en el estándar de 50Hz.

    .. code-block:: arduino

        void setup() {
            // Attach the servo to the specified pin and set its pulse width range
            myServo.attach(servoPin, minPulseWidth, maxPulseWidth);

            // Set the PWM frequency for the servo
            myServo.setPeriodHertz(50); // Standard 50Hz servo
        }
    
    * ``attach (int pin, int min, int max)``: Esta función conecta el motor servo al pin GPIO especificado y establece los anchos de pulso mínimo y máximo para el servo.

        * ``pin``: El número del pin GPIO al cual está conectado el servo.
        * ``min`` y ``max``: los anchos de pulso mínimo y máximo, respectivamente, en microsegundos. Estos valores definen el rango de movimiento del motor servo.

    * ``setPeriodHertz(int hertz)``: Esta función establece la frecuencia PWM para el motor servo en hertz.

        * ``hertz``: La frecuencia PWM deseada en hertz. La frecuencia PWM predeterminada para servos es 50Hz, lo cual es adecuado para la mayoría de las aplicaciones.


#. La función ``loop`` es la parte principal del código que se ejecuta continuamente. Rota el motor servo de 0 a 180 grados y luego vuelve a 0 grados. Esto se logra mapeando el ángulo a la anchura de pulso correspondiente y actualizando el motor servo con el nuevo valor de anchura de pulso.

    .. code-block:: arduino

        void loop() {
            // Rotate the servo from 0 to 180 degrees
            for (int angle = 0; angle <= 180; angle++) {
                int pulseWidth = map(angle, 0, 180, minPulseWidth, maxPulseWidth);
                myServo.writeMicroseconds(pulseWidth);
                delay(15);
            }

            // Rotate the servo from 180 to 0 degrees
            for (int angle = 180; angle >= 0; angle--) {
                int pulseWidth = map(angle, 0, 180, minPulseWidth, maxPulseWidth);
                myServo.writeMicroseconds(pulseWidth);
                delay(15);
            }
        }

    * ``writeMicroseconds(int value)``: Esta función establece el ancho de pulso del motor servo en microsegundos.

            * ``value``: El ancho de pulso deseado en microsegundos.

            La función ``writeMicroseconds(int value)`` toma un valor entero como argumento, representando el ancho de pulso deseado en microsegundos. Este valor típicamente debe estar dentro del rango especificado por los anchos de pulso mínimo y máximo (``minPulseWidth`` y ``maxPulseWidth``) definidos previamente en el código. Luego, la función establece el ancho de pulso para el motor servo, causando que se mueva a la posición correspondiente.