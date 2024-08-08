

.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _iot_intrusion_alert_system:

8.9 Sistema de Notificación de Intrusión Basado en Blynk
========================================================

Este proyecto demuestra un sistema simple de detección de intrusiones en el hogar usando un sensor de movimiento PIR (HC-SR501).
Cuando el sistema está configurado en modo "Ausente" a través de la aplicación Blynk, el sensor PIR monitorea el movimiento.
Cualquier movimiento detectado activa una notificación en la aplicación Blynk, alertando al usuario de una posible intrusión.

**Componentes Necesarios**

Para este proyecto, necesitamos los siguientes componentes.

Es definitivamente conveniente comprar un kit completo, aquí está el enlace:

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

    *   - INTRODUCCIÓN AL COMPONENTE
        - ENLACE DE COMPRA

    *   - :ref:`cpn_esp32_wroom_32e`
        - |link_esp32_wroom_32e_buy|
    *   - :ref:`cpn_esp32_camera_extension`
        - |link_esp32_extension_board|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_pir`
        - |link_pir_buy|


1. Montaje del Circuito
--------------------------

.. image:: ../../img/wiring/iot_9_blynk_bb.png
    :width: 60%
    :align: center

2. Configuración de Blynk
------------------------------------

**2.1 Inicializando Blynk**

1. Ve a la página de |link_blynk| y selecciona **Sign Up FREE** o **Enterprise Solution**.

    .. image:: img/09_blynk_access.png
        :width: 600
        :align: center

2. Ingresa tu correo electrónico para comenzar el proceso de registro.

    .. image:: img/09_blynk_sign_in.png
        :align: center

3. Revisa tu correo electrónico para ver un mensaje, y haz clic en el enlace **Create Password** en el correo para establecer tu contraseña.

    .. image:: img/09_blynk_password.png
        :align: center

4. Después de la confirmación, comenzará un **Blynk Tour** donde podrás aprender rápidamente sobre algunas de las características clave de Blynk.

    .. image:: img/09_blynk_tour.png
        :width: 600
        :align: center

5. Después de completar el Blynk Tour, aparecerá una ventana donde podrás elegir explorar Blueprints o hacer clic en Quick Start para conectar rápidamente tu dispositivo. Sin embargo, en este caso, seleccionaremos "Have a look around first".

    .. image:: img/09_blynk_skip.png
        :align: center

**2.2 Creación de Plantillas**

1. Comienza creando una plantilla en Blynk. Sigue los pasos para configurar la plantilla **Intrusion Alert System**.

    .. image:: img/09_create_template_1_shadow.png
        :width: 600
        :align: center

2. Nombra tu plantilla, elige **ESP32** como el Hardware, selecciona **WiFi** como el **Tipo de Conexión**, y luego haz clic en **Done**.

   .. image:: img/09_create_template_2_shadow.png
        :width: 600
        :align: center

3. Entra en la plantilla, donde se te indicarán los siguientes pasos. Haz clic en **Configure template** para subir una imagen de portada, mejorar la descripción y más. Sigue los tres pasos restantes para completar la configuración.

    .. image:: img/09_blynk_temp_steps.png
        :width: 600
        :align: center

**2.3 Configurar Datastreams**

1. Abre la plantilla recién creada y ve a la página de configuración de datastreams.

   .. image:: img/09_blynk_new_datastream.png
        :width: 600
        :align: center

2. Haz clic en **New Datastream**, y en la ventana emergente, selecciona **Virtual Pin**.

   .. image:: img/09_blynk_datastream_virtual.png
        :width: 600
        :align: center

3. Nombra el **Virtual Pin V0** como **AwayMode** y establece el **TIPO DE DATO** en **Integer**, con valores **MIN** y **MAX** de **0** y **1**.

   .. image:: img/09_create_template_shadow.png
        :width: 600
        :align: center

4. De manera similar, crea otro **Virtual Pin** llamado **Current Status** y establece el **TIPO DE DATO** en **String**.

   .. image:: img/09_datastream_1_shadow.png
        :width: 600
        :align: center

**2.4 Configurar el Tablero Web**

1. Arrastra y suelta tanto el **Switch widget** como el **Label widget** en el **Tablero Web**.

   .. image:: img/09_web_dashboard_1_shadow.png
        :width: 600
        :align: center

2. Pasa el cursor sobre un widget para ver tres iconos. Utiliza el icono de **Configuración** para configurar las propiedades del widget.

   .. image:: img/09_blynk_dashboard_set.png
        :width: 600
        :align: center

3. Configura el **Switch widget** para que se enlace con el datastream **AwayMode(V0)**, estableciendo las etiquetas **ONLABEL** y **OFFLABEL** para mostrar **"away home"** y **"at home"** respectivamente.

   .. image:: img/09_web_dashboard_2_shadow.png
        :width: 600
        :align: center

4. En la configuración del **Label widget**, enlázalo con el datastream **Current Status(V1)**.

   .. image:: img/09_web_dashboard_3_shadow.png
        :width: 600
        :align: center

**2.5 Configuración de un Evento**

1. Haz clic en **Events & Notifications** y luego en **Create Event**.

   .. image:: img/09_blynk_event_add.png
        :width: 600
        :align: center

2. Nombra el evento y especifica su código. Elige **Warning** para **TIPO** y proporciona una breve descripción para el correo electrónico de notificación. Ajusta la frecuencia de notificación según lo desees.

   .. note::

      Asegúrate de que el **CÓDIGO DEL EVENTO** esté configurado como ``intrusion_detected``. Cualquier cambio aquí requiere ajustes correspondientes en el código.

   .. image:: img/09_event_1_shadow.png
        :width: 600
        :align: center

3. Ve a la sección de **Notificaciones** para habilitar las notificaciones y configurar los ajustes de correo electrónico.

   .. image:: img/09_event_2_shadow.png
        :width: 600
        :align: center

4. En **Configuración**, define con qué frecuencia un evento activa las notificaciones y establece los intervalos según tu preferencia. Recuerda hacer clic en **Create** para guardar tus configuraciones.

   .. image:: img/09_event_3_shadow.png
        :width: 600
        :align: center

**2.6 Guardar la Plantilla**

1. Recuerda guardar tus cambios en la plantilla.

   .. image:: img/09_save_template_shadow.png
        :width: 600
        :align: center

**2.7 Crear un Dispositivo**

1. Es hora de crear un nuevo dispositivo a partir de la plantilla.

   .. image:: img/09_blynk_device_new.png
        :width: 600
        :align: center

2. Selecciona **From template** para comenzar.

   .. image:: img/09_blynk_device_template.png
        :width: 600
        :align: center

3. Elige la plantilla **Intrusion Alert System** y haz clic en **Create**.

   .. image:: img/09_blynk_device_template2.png
        :width: 600
        :align: center

4. Anota el **Template ID**, **Device Name** y **AuthToken** para la integración con tu ESP32.

   .. image:: img/09_blynk_device_code.png
        :width: 600
        :align: center

3. Ejecución del Código
-----------------------------
#. Antes de ejecutar el código, asegúrate de instalar la biblioteca ``Blynk`` desde el **Administrador de Bibliotecas** en el Arduino IDE.

    .. image:: img/09_blynk_add_library.png
        :width: 700
        :align: center

#. Abre el archivo ``iot_9_intrusion_alert_system.ino``, ubicado en el directorio ``esp32-starter-kit-main\c\codes\iot_9_intrusion_alert_system``. También puedes copiar su contenido en el Arduino IDE.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/16bca228-64d7-4519-ac3b-833afecfcc65/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Sustituye los marcadores de posición de ``BLYNK_TEMPLATE_ID``, ``BLYNK_TEMPLATE_NAME`` y ``BLYNK_AUTH_TOKEN`` por tus propios IDs únicos.

    .. code-block:: arduino
    
        #define BLYNK_TEMPLATE_ID "TMPxxxxxxx"
        #define BLYNK_TEMPLATE_NAME "Intrusion Alert System"
        #define BLYNK_AUTH_TOKEN "xxxxxxxxxxxxx"

#. También necesitas ingresar el ``ssid`` y ``password`` de tu red WiFi.

   .. code-block:: arduino

        char ssid[] = "your_ssid";
        char pass[] = "your_password";

#. Elige la placa correcta (**ESP32 Dev Module**) y puerto, luego haz clic en el botón **Subir**.

#. Abre el Monitor Serial (configura la tasa de baudios a 115200) y espera un mensaje de conexión exitosa.

    .. image:: img/09_blynk_upload_code.png
        :align: center

#. Tras una conexión exitosa, activar el interruptor en Blynk iniciará la vigilancia del módulo PIR. Cuando se detecte movimiento (estado de 1), dirá, "¡Alguien aquí!" y enviará una alerta a tu correo electrónico.

    .. image:: img/09_blynk_code_alarm.png
        :width: 700
        :align: center

4. Explicación del Código
-----------------------------

#. **Configuración & Bibliotecas**

   Aquí, configuras las constantes y credenciales de Blynk. También incluyes las bibliotecas necesarias para el ESP32 y Blynk.

    .. code-block:: arduino

        /* Comment this out to disable prints and save space */
        #define BLYNK_PRINT Serial

        #define BLYNK_TEMPLATE_ID "xxxxxxxxxxx"
        #define BLYNK_TEMPLATE_NAME "Intrusion Alert System"
        #define BLYNK_AUTH_TOKEN "xxxxxxxxxxxxxxxxxxxxxxxxxxx"

        #include <WiFi.h>
        #include <WiFiClient.h>
        #include <BlynkSimpleEsp32.h>

#. **Configuración WiFi**

   Ingresa tus credenciales WiFi.

   .. code-block:: arduino

        char ssid[] = "your_ssid";
        char pass[] = "your_password";

#. **Configuración del Sensor PIR**

   Establece el pin donde está conectado el sensor PIR e inicializa las variables de estado.

   .. code-block:: arduino

      const int sensorPin = 14;
      int state = 0;
      int awayHomeMode = 0;
      BlynkTimer timer;

#. **Función setup()**

   Esta función inicializa el sensor PIR como entrada, configura la comunicación serial, se conecta a WiFi y configura Blynk.

   - Usamos ``timer.setInterval(1000L, myTimerEvent)`` para establecer el intervalo del temporizador en ``setup()``, aquí lo configuramos para ejecutar la función ``myTimerEvent()`` cada **1000ms**. Puedes modificar el primer parámetro de ``timer.setInterval(1000L, myTimerEvent)`` para cambiar el intervalo entre ejecuciones de ``myTimerEvent``.

   .. raw:: html
    
    <br/> 

   .. code-block:: arduino

        void setup() {

            pinMode(sensorPin, INPUT);  // Set PIR sensor pin as input
            Serial.begin(115200);           // Start serial communication at 115200 baud rate for debugging
            
            // Configure Blynk and connect to WiFi
            Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
            
            timer.setInterval(1000L, myTimerEvent);  // Setup a function to be called every second
        }

#. **Función loop()**

   La función loop ejecuta continuamente Blynk y las funciones del temporizador de Blynk.

   .. code-block:: arduino

        void loop() {
           Blynk.run();
           timer.run();
        }

#. **Interacción con la Aplicación Blynk**

   Estas funciones se llaman cuando el dispositivo se conecta a Blynk y cuando hay un cambio en el estado del pin virtual V0 en la aplicación Blynk.

   - Cada vez que el dispositivo se conecta al servidor Blynk, o se reconecta debido a condiciones de red deficientes, se llama a la función ``BLYNK_CONNECTED()``. El comando ``Blynk.syncVirtual()`` solicita el valor de un Pin Virtual único. El Pin Virtual especificado realizará la llamada ``BLYNK_WRITE()``.

   - Siempre que el valor de un pin virtual en el servidor BLYNK cambia, se activará ``BLYNK_WRITE()``.

   .. raw:: html
    
    <br/> 

   .. code-block:: arduino
      
        // This function is called every time the device is connected to the Blynk.Cloud
        BLYNK_CONNECTED() {
            Blynk.syncVirtual(V0);
        }
      
        // This function is called every time the Virtual Pin 0 state changes
        BLYNK_WRITE(V0) {
            awayHomeMode = param.asInt();
            // additional logic
        }

#. **Manejo de Datos**

   Cada segundo, la función ``myTimerEvent()`` llama a ``sendData()``. Si el modo ausente está habilitado en Blynk, verifica el sensor PIR y envía una notificación a Blynk si se detecta movimiento.

   - Usamos ``Blynk.virtualWrite(V1, "¡Alguien en tu casa! ¡Por favor, revisa!");`` para cambiar el texto de una etiqueta.

   - Usa ``Blynk.logEvent("intrusion_detected");`` para registrar el evento en Blynk.

   .. raw:: html
    
    <br/> 

   .. code-block:: arduino

        void myTimerEvent() {
           sendData();
        }

        void sendData() {
           if (awayHomeMode == 1) {
              state = digitalRead(sensorPin);  // Read the state of the PIR sensor

              Serial.print("state:");
              Serial.println(state);

              // If the sensor detects movement, send an alert to the Blynk app
              if (state == HIGH) {
                Serial.println("Somebody here!");
                Blynk.virtualWrite(V1, "Somebody in your house! Please check!");
                 Blynk.logEvent("intrusion_detected");
              }
           }
        }

**Reference**

- |link_blynk_doc|
- |link_blynk_quickstart| 
- |link_blynk_virtualWrite|
- |link_blynk_logEvent|
- |link_blynk_timer_intro|
- |link_blynk_syncing| 
- |link_blynk_write|