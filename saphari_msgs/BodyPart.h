#ifndef _ROS_saphari_msgs_BodyPart_h
#define _ROS_saphari_msgs_BodyPart_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point32.h"

namespace saphari_msgs
{

  class BodyPart : public ros::Msg
  {
    public:
      int32_t id;
      int32_t label;
      uint8_t childIDs_length;
      int32_t st_childIDs;
      int32_t * childIDs;
      geometry_msgs::Point32 centroid;
      float radius;
      enum { LEFTFOOT = 0 };
      enum { LEFTLEG = 1 };
      enum { LEFTKNEE = 2 };
      enum { LEFTTHIGH = 3 };
      enum { RIGHTFOOT = 4 };
      enum { RIGHTLEG = 5 };
      enum { RIGHTKNEE = 6 };
      enum { RIGHTTHIGH = 7 };
      enum { RIGHTHIP = 8 };
      enum { LEFTHIP = 9 };
      enum { NECK = 10 };
      enum { RIGHTARM = 11 };
      enum { RIGHTELBOW = 12 };
      enum { RIGHTFOREARM = 13 };
      enum { RIGHTHAND = 14 };
      enum { LEFTARM = 15 };
      enum { LEFTELBOW = 16 };
      enum { FOREARM = 17 };
      enum { LEFTHAND = 18 };
      enum { LEFTBOTTOMFACE = 19 };
      enum { RIGHTBOTTOMFACE = 20 };
      enum { LEFTTOPFACE = 21 };
      enum { RIGHTTOPFACE = 22 };
      enum { RIGHTCHEST = 23 };
      enum { LEFTCHEST = 24 };
      enum { HEAD = 96 };
      enum { TORSO = 97 };
      enum { RIGHTSHOULDER = 98 };
      enum { LEFTSHOULDER = 99 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_id;
      u_id.real = this->id;
      *(outbuffer + offset + 0) = (u_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->id);
      union {
        int32_t real;
        uint32_t base;
      } u_label;
      u_label.real = this->label;
      *(outbuffer + offset + 0) = (u_label.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_label.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_label.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_label.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->label);
      *(outbuffer + offset++) = childIDs_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < childIDs_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_childIDsi;
      u_childIDsi.real = this->childIDs[i];
      *(outbuffer + offset + 0) = (u_childIDsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_childIDsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_childIDsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_childIDsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->childIDs[i]);
      }
      offset += this->centroid.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_radius;
      u_radius.real = this->radius;
      *(outbuffer + offset + 0) = (u_radius.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_radius.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_radius.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_radius.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->radius);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_id;
      u_id.base = 0;
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->id = u_id.real;
      offset += sizeof(this->id);
      union {
        int32_t real;
        uint32_t base;
      } u_label;
      u_label.base = 0;
      u_label.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_label.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_label.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_label.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->label = u_label.real;
      offset += sizeof(this->label);
      uint8_t childIDs_lengthT = *(inbuffer + offset++);
      if(childIDs_lengthT > childIDs_length)
        this->childIDs = (int32_t*)realloc(this->childIDs, childIDs_lengthT * sizeof(int32_t));
      offset += 3;
      childIDs_length = childIDs_lengthT;
      for( uint8_t i = 0; i < childIDs_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_childIDs;
      u_st_childIDs.base = 0;
      u_st_childIDs.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_childIDs.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_childIDs.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_childIDs.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_childIDs = u_st_childIDs.real;
      offset += sizeof(this->st_childIDs);
        memcpy( &(this->childIDs[i]), &(this->st_childIDs), sizeof(int32_t));
      }
      offset += this->centroid.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_radius;
      u_radius.base = 0;
      u_radius.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_radius.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_radius.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_radius.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->radius = u_radius.real;
      offset += sizeof(this->radius);
     return offset;
    }

    const char * getType(){ return "saphari_msgs/BodyPart"; };
    const char * getMD5(){ return "f97d66c4403cdacb1c743e356fc26b62"; };

  };

}
#endif