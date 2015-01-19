#ifndef _ROS_SERVICE_Segment_h
#define _ROS_SERVICE_Segment_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/PointCloud2.h"

namespace rail_segmentation
{

static const char SEGMENT[] = "rail_segmentation/Segment";

  class SegmentRequest : public ros::Msg
  {
    public:
      bool clear;
      bool useMapFrame;
      bool segmentOnRobot;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_clear;
      u_clear.real = this->clear;
      *(outbuffer + offset + 0) = (u_clear.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->clear);
      union {
        bool real;
        uint8_t base;
      } u_useMapFrame;
      u_useMapFrame.real = this->useMapFrame;
      *(outbuffer + offset + 0) = (u_useMapFrame.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->useMapFrame);
      union {
        bool real;
        uint8_t base;
      } u_segmentOnRobot;
      u_segmentOnRobot.real = this->segmentOnRobot;
      *(outbuffer + offset + 0) = (u_segmentOnRobot.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->segmentOnRobot);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_clear;
      u_clear.base = 0;
      u_clear.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->clear = u_clear.real;
      offset += sizeof(this->clear);
      union {
        bool real;
        uint8_t base;
      } u_useMapFrame;
      u_useMapFrame.base = 0;
      u_useMapFrame.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->useMapFrame = u_useMapFrame.real;
      offset += sizeof(this->useMapFrame);
      union {
        bool real;
        uint8_t base;
      } u_segmentOnRobot;
      u_segmentOnRobot.base = 0;
      u_segmentOnRobot.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->segmentOnRobot = u_segmentOnRobot.real;
      offset += sizeof(this->segmentOnRobot);
     return offset;
    }

    const char * getType(){ return SEGMENT; };
    const char * getMD5(){ return "ef297f07b3a4a35daa8b4c11d11c998e"; };

  };

  class SegmentResponse : public ros::Msg
  {
    public:
      uint8_t objects_length;
      sensor_msgs::PointCloud2 st_objects;
      sensor_msgs::PointCloud2 * objects;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = objects_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < objects_length; i++){
      offset += this->objects[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t objects_lengthT = *(inbuffer + offset++);
      if(objects_lengthT > objects_length)
        this->objects = (sensor_msgs::PointCloud2*)realloc(this->objects, objects_lengthT * sizeof(sensor_msgs::PointCloud2));
      offset += 3;
      objects_length = objects_lengthT;
      for( uint8_t i = 0; i < objects_length; i++){
      offset += this->st_objects.deserialize(inbuffer + offset);
        memcpy( &(this->objects[i]), &(this->st_objects), sizeof(sensor_msgs::PointCloud2));
      }
     return offset;
    }

    const char * getType(){ return SEGMENT; };
    const char * getMD5(){ return "aa27a226ea8753f74a4b53346f49b548"; };

  };

  class Segment {
    public:
    typedef SegmentRequest Request;
    typedef SegmentResponse Response;
  };

}
#endif
