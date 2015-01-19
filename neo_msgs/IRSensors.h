#ifndef _ROS_neo_msgs_IRSensors_h
#define _ROS_neo_msgs_IRSensors_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace neo_msgs
{

  class IRSensors : public ros::Msg
  {
    public:
      int32_t measurement[4];

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint8_t i = 0; i < 4; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_measurementi;
      u_measurementi.real = this->measurement[i];
      *(outbuffer + offset + 0) = (u_measurementi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_measurementi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_measurementi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_measurementi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->measurement[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint8_t i = 0; i < 4; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_measurementi;
      u_measurementi.base = 0;
      u_measurementi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_measurementi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_measurementi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_measurementi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->measurement[i] = u_measurementi.real;
      offset += sizeof(this->measurement[i]);
      }
     return offset;
    }

    const char * getType(){ return "neo_msgs/IRSensors"; };
    const char * getMD5(){ return "0b608e536c75438a771e1cfb29f4b570"; };

  };

}
#endif