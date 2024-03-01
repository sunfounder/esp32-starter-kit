

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
        - \-
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
----------------------------

**2.1 Inicialización de Blynk**

#. Navega a |link_blynk| y selecciona **EMPEZAR GRATIS**.

   .. image:: img/09_blynk_access.png
        :width: 90%

#. Ingresa tu correo electrónico para iniciar el proceso de registro.

   .. image:: img/09_blynk_sign_in.png
        :width: 70%
        :align: center

#. Confirma tu registro a través de tu correo electrónico.

    .. image:: img/09_blynk_password.png
        :width: 90%

#. Después de la confirmación, aparecerá **Tour de Blynk**. Se recomienda seleccionar "Omitir". Si también aparece **Inicio Rápido**, considera omitirlo igualmente.
   
    .. image:: img/09_blynk_tour.png
        :width: 90%

**2.2 Creación de Plantilla**

#. Primero, crea una plantilla en Blynk. Sigue las instrucciones subsiguientes para crear la plantilla **Sistema de Alerta de Intrusión**.

    .. image:: img/09_create_template_1_shadow.png
        :width: 700
        :align: center

#. Asigna un nombre a la plantilla, selecciona **ESP32** como Hardware y **Tipo de Conexión** como **WiFi**, luego selecciona **Hecho**.

    .. image:: img/09_create_template_2_shadow.png
        :width: 700
        :align: center

**2.3 Generación de Flujo de Datos**

Abre la plantilla que acabas de configurar, vamos a crear dos flujos de datos.

#. Haz clic en **Nuevo Flujo de Datos**.

    .. image:: img/09_blynk_new_datastream.png
        :width: 700
        :align: center

#. En el popup, elige **Pin Virtual**.

    .. image:: img/09_blynk_datastream_virtual.png
        :width: 700
        :align: center

#. Nombra el **Pin Virtual V0** como **ModoAusente**. Establece el **TIPO DE DATO** como **Entero** con valores **MIN** y **MAX** como **0** y **1**.

    .. image:: img/09_create_template_shadow.png
        :width: 700
        :align: center

#. De manera similar, crea otro flujo de datos de **Pin Virtual**. Nómbralo **Estado Actual** y establece el **TIPO DE DATO** a **Cadena**.

    .. image:: img/09_datastream_1_shadow.png
        :width: 700
        :align: center

**2.4 Configuración de un Evento**

A continuación, configuraremos un evento que envía una notificación por correo electrónico si se detecta una intrusión.

#. Haz clic en **Añadir Nuevo Evento**.

    .. image:: img/09_blynk_event_add.png
        
#. Define el nombre del evento y su código específico. Para **TIPO**, elige **Advertencia** y escribe una breve descripción para el correo que se enviará cuando ocurra el evento. También puedes ajustar con qué frecuencia recibes notificaciones.

    .. note::
        
        Asegúrate de que el **CÓDIGO DEL EVENTO** esté establecido como ``intrusion_detected``. Esto está predefinido en el código, por lo que cualquier cambio significaría que necesitas ajustar el código también.

    .. image:: img/09_event_1_shadow.png
        :width: 700
        :align: center

#. Ve a la sección de **Notificaciones** para activar las notificaciones y configurar los detalles del correo electrónico.

    .. image:: img/09_event_2_shadow.png
        :width: 80%
        :align: center

.. raw:: html
    
    <br/> 

**2.5 Ajuste Fino del Tablero Web**

Asegurarse de que el **Tablero Web** interactúe perfectamente con el Sistema de Alerta de Intrusión es vital.

#. Simplemente arrastra y coloca tanto el **Widget de Interruptor** como el **Widget de Etiqueta** en el **Tablero Web**.

    .. image:: img/09_web_dashboard_1_shadow.png
        :width: 100%
        :align: center

#. Cuando pases el cursor sobre un widget, aparecerán tres iconos. Usa el icono de configuración para ajustar las propiedades del widget.

    .. image:: img/09_blynk_dashboard_set.png
        :width: 100%
        :align: center

#. En la configuración del **Widget de Interruptor**, selecciona **Flujo de Datos** como **ModoAusente(V0)**. Establece **EtiquetaON** y **EtiquetaOFF** para mostrar **"ausente"** y **"casa"**, respectivamente.

    .. image:: img/09_web_dashboard_2_shadow.png
        :width: 100%
        :align: center

#. En la configuración del **Widget de Etiqueta**, selecciona **Flujo de Datos** como **Estado Actual(V1)**.

    .. image:: img/09_web_dashboard_3_shadow.png
        :width: 100%
        :align: center

**2.6 Guardando la Plantilla**

Por último, no olvides guardar tu plantilla.

    .. image:: img/09_save_template_shadow.png
        :width: 100%
        :align: center

**2.7 Creando un Dispositivo**

#. Es hora de crear un nuevo dispositivo.

    .. image:: img/09_blynk_device_new.png
        :width: 700
        :align: center

#. Haz clic en **Desde plantilla** para comenzar con una nueva configuración.

    .. image:: img/09_blynk_device_template.png
        :width: 700
        :align: center

#. Luego, elige la plantilla **Sistema de Alerta de Intrusión** y haz clic en **Crear**.

    .. image:: img/09_blynk_device_template2.png
        :width: 700
        :align: center

#. Aquí, verás el ``ID de la Plantilla``, ``Nombre del Dispositivo`` y ``AuthToken``. Necesitas copiar estos en tu código para que el ESP32 pueda trabajar con Blynk.

    .. image:: img/09_blynk_device_code.png
        :width: 700
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