#include "application.h"

#define PUSHBULLET_NOTIF_HOME "pushbulletHOME"         //-> family group in pushbullet
#define PUSHBULLET_NOTIF_PERSONAL "pushbulletPERSONAL" //-> only my phone
#define GOOGLE_DOCS "googleDocs" //-> log stuff into a google docs spreadsheet

/*******************************************************************************
 * Function Name  : getTime
 * Description    : returns the time in the following format: 14:42:31
                    TIME_FORMAT_ISO8601_FULL example: 2016-03-23T14:42:31-04:00
 * Return         : the time
 *******************************************************************************/
String getTime() {
  String timeNow = Time.format(Time.now(), TIME_FORMAT_ISO8601_FULL);
  timeNow = timeNow.substring(11, timeNow.length()-6);
  return " " + timeNow;
}

/*******************************************************************************
 * Function Name  : float2string
 * Description    : return the string representation of the float number
                     passed as parameter with 2 decimals
 * Return         : the string
 *******************************************************************************/
String float2string( float floatNumber )
{
  String stringNumber = String(floatNumber);

  //return only 2 decimals
  // Example: show 19.00 instead of 19.000000
  stringNumber = stringNumber.substring(0, stringNumber.length()-4);

  return stringNumber;
}

/*******************************************************************************
 * Function Name  : logMessage
 * Description    : publish a message to a google spreadsheet, pushbullet or simply to the particle console
 * Return         : none
 *******************************************************************************/
void logMessage(String message) {
  Particle.publish(GOOGLE_DOCS, "{\"my-name\":\"" + message + "\"}", 60, PRIVATE);
}
