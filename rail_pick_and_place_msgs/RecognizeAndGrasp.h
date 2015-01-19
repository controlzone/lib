#ifndef _ROS_SERVICE_RecognizeAndGrasp_h
#define _ROS_SERVICE_RecognizeAndGrasp_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/PointCloud.h"

namespace rail_pick_and_place_msgs
{

static const char RECOGNIZEANDGRASP[] = "rail_pick_and_place_msgs/RecognizeAndGrasp";

  class RecognizeAndGraspRequest : public ros::Msg
  {
    public:
      sensor_msgs::PointCloud cloud;
      int8_t numAttempts;
      uint8_t objectIndices_length;
      int16_t st_objectIndices;
      int16_t * objectIndices;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->cloud.serialize(outbuffer + offset);
      union {
        int8_t real;
        uint8_t base;
      } u_numAttempts;
      u_numAttempts.real = this->numAttempts;
      *(outbuffer + offset + 0) = (u_numAttempts.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->numAttempts);
      *(outbuffer + offset++) = objectIndices_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < objectIndices_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_objectIndicesi;
      u_objectIndicesi.real = this->objectIndices[i];
      *(outbuffer + offset + 0) = (u_objectIndicesi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_objectIndicesi.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->objectIndices[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->cloud.deserialize(inbuffer + offset);
      union {
        int8_t real;
        uint8_t base;
      } u_numAttempts;
      u_numAttempts.base = 0;
      u_numAttempts.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->numAttempts = u_numAttempts.real;
      offset += sizeof(this->numAttempts);
      uint8_t objectIndices_lengthT = *(inbuffer + offset++);
      if(objectIndices_lengthT > objectIndices_length)
        this->objectIndices = (int16_t*)realloc(this->objectIndices, objectIndices_lengthT * sizeof(int16_t));
      offset += 3;
      objectIndices_length = objectIndices_lengthT;
      for( uint8_t i = 0; i < objectIndices_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_st_objectIndices;
      u_st_objectIndices.base = 0;
      u_st_objectIndices.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_objectIndices.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_objectIndices = u_st_objectIndices.real;
      offset += sizeof(this->st_objectIndices);
        memcpy( &(this->objectIndices[i]), &(this->st_objectIndices), sizeof(int16_t));
      }
     return offset;
    }

    const char * getType(){ return RECOGNIZEANDGRASP; };
    const char * getMD5(){ return "ba138fabeb6a4c28d527ca5807ed5bf1"; };

  };

  class RecognizeAndGraspResponse : public ros::Msg
  {
    public:
      bool success;
      int16_t objectIndex;

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
      union {
        int16_t real;
        uint16_t base;
      } u_objectIndex;
      u_objectIndex.real = this->objectIndex;
      *(outbuffer + offset + 0) = (u_objectIndex.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_objectIndex.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->objectIndex);
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
      union {
        int16_t real;
        uint16_t base;
      } u_objectIndex;
      u_objectIndex.base = 0;
      u_objectIndex.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_objectIndex.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->objectIndex = u_objectIndex.real;
      offset += sizeof(this->objectIndex);
     return offset;
    }

    const char * getType(){ return RECOGNIZEANDGRASP; };
    const char * getMD5(){ return "e6e454c0520e073714859083f72a4f8e"; };

  };

  class RecognizeAndGrasp {
    public:
    typedef RecognizeAndGraspRequest Request;
    typedef RecognizeAndGraspResponse Response;
  };

}
#endif
