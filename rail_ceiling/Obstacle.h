#ifndef _ROS_rail_ceiling_Obstacle_h
#define _ROS_rail_ceiling_Obstacle_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Polygon.h"

namespace rail_ceiling
{

  class Obstacle : public ros::Msg
  {
    public:
      int32_t id;
      uint8_t polygons_length;
      geometry_msgs::Polygon st_polygons;
      geometry_msgs::Polygon * polygons;

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
      *(outbuffer + offset++) = polygons_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < polygons_length; i++){
      offset += this->polygons[i].serialize(outbuffer + offset);
      }
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
      uint8_t polygons_lengthT = *(inbuffer + offset++);
      if(polygons_lengthT > polygons_length)
        this->polygons = (geometry_msgs::Polygon*)realloc(this->polygons, polygons_lengthT * sizeof(geometry_msgs::Polygon));
      offset += 3;
      polygons_length = polygons_lengthT;
      for( uint8_t i = 0; i < polygons_length; i++){
      offset += this->st_polygons.deserialize(inbuffer + offset);
        memcpy( &(this->polygons[i]), &(this->st_polygons), sizeof(geometry_msgs::Polygon));
      }
     return offset;
    }

    const char * getType(){ return "rail_ceiling/Obstacle"; };
    const char * getMD5(){ return "76df1f2472e90d5749f77c8c79dfc762"; };

  };

}
#endif