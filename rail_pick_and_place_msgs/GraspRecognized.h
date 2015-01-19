#ifndef _ROS_SERVICE_GraspRecognized_h
#define _ROS_SERVICE_GraspRecognized_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"

namespace rail_pick_and_place_msgs
{

static const char GRASPRECOGNIZED[] = "rail_pick_and_place_msgs/GraspRecognized";

  class GraspRecognizedRequest : public ros::Msg
  {
    public:
      int8_t numAttempts;
      int32_t objectIndex;
      uint8_t grasps_length;
      geometry_msgs::PoseStamped st_grasps;
      geometry_msgs::PoseStamped * grasps;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_numAttempts;
      u_numAttempts.real = this->numAttempts;
      *(outbuffer + offset + 0) = (u_numAttempts.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->numAttempts);
      union {
        int32_t real;
        uint32_t base;
      } u_objectIndex;
      u_objectIndex.real = this->objectIndex;
      *(outbuffer + offset + 0) = (u_objectIndex.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_objectIndex.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_objectIndex.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_objectIndex.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->objectIndex);
      *(outbuffer + offset++) = grasps_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < grasps_length; i++){
      offset += this->grasps[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_numAttempts;
      u_numAttempts.base = 0;
      u_numAttempts.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->numAttempts = u_numAttempts.real;
      offset += sizeof(this->numAttempts);
      union {
        int32_t real;
        uint32_t base;
      } u_objectIndex;
      u_objectIndex.base = 0;
      u_objectIndex.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_objectIndex.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_objectIndex.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_objectIndex.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->objectIndex = u_objectIndex.real;
      offset += sizeof(this->objectIndex);
      uint8_t grasps_lengthT = *(inbuffer + offset++);
      if(grasps_lengthT > grasps_length)
        this->grasps = (geometry_msgs::PoseStamped*)realloc(this->grasps, grasps_lengthT * sizeof(geometry_msgs::PoseStamped));
      offset += 3;
      grasps_length = grasps_lengthT;
      for( uint8_t i = 0; i < grasps_length; i++){
      offset += this->st_grasps.deserialize(inbuffer + offset);
        memcpy( &(this->grasps[i]), &(this->st_grasps), sizeof(geometry_msgs::PoseStamped));
      }
     return offset;
    }

    const char * getType(){ return GRASPRECOGNIZED; };
    const char * getMD5(){ return "9cb1e165f5eec09e82d77bf1da29c4cb"; };

  };

  class GraspRecognizedResponse : public ros::Msg
  {
    public:
      bool success;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    const char * getType(){ return GRASPRECOGNIZED; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class GraspRecognized {
    public:
    typedef GraspRecognizedRequest Request;
    typedef GraspRecognizedResponse Response;
  };

}
#endif
