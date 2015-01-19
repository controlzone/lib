#ifndef _ROS_SERVICE_GetAllObstacles_h
#define _ROS_SERVICE_GetAllObstacles_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "rail_ceiling/Obstacle.h"

namespace rail_ceiling
{

static const char GETALLOBSTACLES[] = "rail_ceiling/GetAllObstacles";

  class GetAllObstaclesRequest : public ros::Msg
  {
    public:

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return GETALLOBSTACLES; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetAllObstaclesResponse : public ros::Msg
  {
    public:
      uint8_t localizationObstacles_length;
      rail_ceiling::Obstacle st_localizationObstacles;
      rail_ceiling::Obstacle * localizationObstacles;
      uint8_t navigationObstacles_length;
      rail_ceiling::Obstacle st_navigationObstacles;
      rail_ceiling::Obstacle * navigationObstacles;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = localizationObstacles_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < localizationObstacles_length; i++){
      offset += this->localizationObstacles[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = navigationObstacles_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < navigationObstacles_length; i++){
      offset += this->navigationObstacles[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t localizationObstacles_lengthT = *(inbuffer + offset++);
      if(localizationObstacles_lengthT > localizationObstacles_length)
        this->localizationObstacles = (rail_ceiling::Obstacle*)realloc(this->localizationObstacles, localizationObstacles_lengthT * sizeof(rail_ceiling::Obstacle));
      offset += 3;
      localizationObstacles_length = localizationObstacles_lengthT;
      for( uint8_t i = 0; i < localizationObstacles_length; i++){
      offset += this->st_localizationObstacles.deserialize(inbuffer + offset);
        memcpy( &(this->localizationObstacles[i]), &(this->st_localizationObstacles), sizeof(rail_ceiling::Obstacle));
      }
      uint8_t navigationObstacles_lengthT = *(inbuffer + offset++);
      if(navigationObstacles_lengthT > navigationObstacles_length)
        this->navigationObstacles = (rail_ceiling::Obstacle*)realloc(this->navigationObstacles, navigationObstacles_lengthT * sizeof(rail_ceiling::Obstacle));
      offset += 3;
      navigationObstacles_length = navigationObstacles_lengthT;
      for( uint8_t i = 0; i < navigationObstacles_length; i++){
      offset += this->st_navigationObstacles.deserialize(inbuffer + offset);
        memcpy( &(this->navigationObstacles[i]), &(this->st_navigationObstacles), sizeof(rail_ceiling::Obstacle));
      }
     return offset;
    }

    const char * getType(){ return GETALLOBSTACLES; };
    const char * getMD5(){ return "1c9abad7770de5c037ab52aab3bbc997"; };

  };

  class GetAllObstacles {
    public:
    typedef GetAllObstaclesRequest Request;
    typedef GetAllObstaclesResponse Response;
  };

}
#endif
