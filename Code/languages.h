// ###############################################################################################################################
// #
// # Code for the printables "Music reactive matrix LED cube" project: https://www.printables.com/de/model/296022-music-reactive-matrix-led-cube
// #
// # Code by https://github.com/AWSW-de with the use of some code from Adafruit examples. See notes at the end of the code too
// #
// # Released under license: GNU General Public License v3.0: https://github.com/AWSW-de/Music-reactive-matrix-LED-cube/blob/main/LICENSE
// #
// # Compatible with code version: V1.0.2
// #
// ###############################################################################################################################


// ###############################################################################################################################
// # Default texts in german language:
// ###############################################################################################################################
// General texts:
String ProjectName, ProjectNameLong, languageSelect, languageInt0, languageInt1, txtSaveSettings;
// LED settings:
String txtSettings, txtLEDsettings, txtLEDcolor, txtIntensity;
// Content and startup:
String txtContentStartup, txtUseLEDtest, txtShowIP;
// Update function:
String txtUpdate0, txtUpdate2, txtUpdate3, txtUpdate4, txtUpdate5;
// WiFi:
String txtWiFi0, txtWiFi1, txtWiFi2;
// Restart
String txtRestart0, txtRestart1, txtRestart2;
// VU-meters and animations:
String txtVU1, txtVU2, txtVU3, txtVU4, txtVU5, txtVU6, txtVU7, txtVU8, txtVU9, txtAnm1, txtAnm2, txtAnm3, txtVUandAnm;
String txtVU1lbl, txtVU2lbl, txtVU3lbl, txtVU4lbl, txtVU5lbl, txtVU6lbl, txtVU7lbl, txtVU8lbl, txtVU9lbl, txtAnm1lbl, txtAnm2lbl, txtAnm3lbl;


void setLanguage(int lang) {
  // ###############################################################################################################################
  // # Translations for: DE
  // ###############################################################################################################################
  if (lang == 0) {  // DEUTSCH
    // Allgemeine Texte:
    ProjectName = "LEDCUBE";
    ProjectNameLong = "Musik reaktiver Matrix-LED Würfel";
    languageSelect = "Sprache";
    languageInt0 = "Deutsch";
    languageInt1 = "Englisch";
    txtSaveSettings = "Einstellungen speichern";

    // LED Einstellungen:
    txtSettings = "Einstellungen";
    txtLEDsettings = "LED Einstellungen";
    txtLEDcolor = "Farbe";
    txtIntensity = "Helligkeit";

    // Anzeigen und Startverhalten:
    txtContentStartup = "Anzeigen und Startverhalten";
    txtUseLEDtest = "LED Start Test anzeigen?";

    // Update Funktion:
    txtUpdate0 = "Update";
    txtUpdate2 = "Über einen der folgenden Links kann die LEDCUBE über den Browser ohne Arduino IDE aktualisiert werden";
    txtUpdate3 = "Hinweis: Es wird eine in der Arduino IDE mit Strg+Alt+S zuvor erstellte .BIN Datei des Sketches benötigt, die über die Option 'Update Firmware' hochgeladen werden kann.";
    txtUpdate4 = "Die notwendige Update-Datei kann hier heruntergeladen werden";
    txtUpdate5 = "Repository auf GitHub";

    // WLAN:
    txtWiFi0 = "WLAN Einstellungen zurücksetzen";
    txtWiFi1 = "WLAN Einstellungen zurücksetzen und neu starten?";
    txtWiFi2 = "Wenn diese Option verwendet wird, werden die WLAN Einstellungen gelöscht";

    // Neustart:
    txtRestart0 = "LEDCUBE neustarten";
    txtRestart1 = "LEDCUBE neustarten?";
    txtRestart2 = "Wenn diese Option verwendet wird, wird das Gerät neu gestartet";

    // VU-meters and animations:
    txtVUandAnm = "Auswahl VU Meter und Animationen";
    txtVU1 = "VU Meter 1";
    txtVU2 = "VU Meter 2";
    txtVU3 = "VU Meter 3";
    txtVU4 = "VU Meter 4";
    txtVU5 = "VU Meter 5";
    txtVU6 = "VU Meter 6";
    txtVU7 = "VU Meter 7";
    txtVU8 = "VU Meter 8";
    txtVU9 = "VU Meter 9";
    txtAnm1 = "Animation 1";
    txtAnm2 = "Animation 2";
    txtAnm3 = "Animation 3";
    txtVU1lbl = "3 farbige Linien";
    txtVU2lbl = "Weiße Linien";
    txtVU3lbl = "Linien mit benutzerdefnierter Farbe";
    txtVU4lbl = "Zufällige LEDs";
    txtVU5lbl = "3-farbige Quadrate";
    txtVU6lbl = "Weiße Quadrate";
    txtVU7lbl = "Klassisch mit weißem Punkt";
    txtVU8lbl = "Klassisch mit RGB Punkt";
    txtVU9lbl = "Klassisch ohne Punkt";
    txtAnm1lbl = "Weißes Flackern";
    txtAnm2lbl = "Regenbogen";
    txtAnm3lbl = "Regenbogen Flackern";
  }


  // ###############################################################################################################################
  // # Translations for: EN
  // ###############################################################################################################################
  if (lang == 1) {  // ENGLISH
    // General texts:
    ProjectName = "LEDCUBE";
    ProjectNameLong = "Music reactive matrix LED cube";
    languageSelect = "Language";
    languageInt0 = "German";
    languageInt1 = "English";
    txtSaveSettings = "Save settings";

    // LED settings:
    txtSettings = "settings";
    txtLEDsettings = "LED settings";
    txtLEDcolor = "Color";
    txtIntensity = "Intensity";

    // Content and startup:
    txtContentStartup = "Content and startup";
    txtUseLEDtest = "Run LED test on startup?";

    // Update function:
    txtUpdate0 = "Update";
    txtUpdate2 = "Using one of the links below, the LEDCUBE can be updated via the browser without the Arduino IDE";
    txtUpdate3 = "Note: A .BIN file of the sketch previously created in the Arduino IDE with Ctrl+Alt+S is required, which can be uploaded via the 'Update Firmware' option.";
    txtUpdate4 = "The necessary update file can be downloaded here";
    txtUpdate5 = "Repository on GitHub";

    // WiFi:
    txtWiFi0 = "Reset WiFi settings";
    txtWiFi1 = "Reset wifi settings and restart?";
    txtWiFi2 = "If this option is used, the WLAN settings will be deleted";

    // Restart:
    txtRestart0 = "Restart LEDCUBE";
    txtRestart1 = "Restart LEDCUBE?";
    txtRestart2 = "If this option is used, the device will be restarted";

    // VU-meters and animations:
    txtVUandAnm = "Selection of VU meters and animations";
    txtVU1 = "VU meter 1";
    txtVU2 = "VU meter 2";
    txtVU3 = "VU meter 3";
    txtVU4 = "VU meter 4";
    txtVU5 = "VU meter 5";
    txtVU6 = "VU meter 6";
    txtVU7 = "VU meter 7";
    txtVU8 = "VU meter 8";
    txtVU9 = "VU meter 9";
    txtAnm1 = "Animation 1";
    txtAnm2 = "Animation 2";
    txtAnm3 = "Animation 3";
    txtVU1lbl = "3 color lines";
    txtVU2lbl = "White lines";
    txtVU3lbl = "Lines with user selected color";
    txtVU4lbl = "Random LED";
    txtVU5lbl = "3 color squares";
    txtVU6lbl = "White squares";
    txtVU7lbl = "Classic with white peak dot";
    txtVU8lbl = "Classic with RGB peak dot";
    txtVU9lbl = "Classic without peak dot";
    txtAnm1lbl = "White flicker";
    txtAnm2lbl = "Rainbow";
    txtAnm3lbl = "Rainbow flicker";
  }
}
// ###############################################################################################################################
// # EOF - You have successfully reached the end of the code - well done ;-)
// ###############################################################################################################################