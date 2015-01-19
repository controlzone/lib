#ifndef _ROS_SERVICE_PerceiveChemLabTool_h
#define _ROS_SERVICE_PerceiveChemLabTool_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/TransformStamped.h"

namespace dna_extraction_msgs
{

static const char PERCEIVECHEMLABTOOL[] = "dna_extraction_msgs/PerceiveChemLabTool";

  class PerceiveChemLabToolRequest : public ros::Msg
  {
    public:
      const char* tool_name;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_tool_name = strlen(this->tool_name);
      memcpy(outbuffer + offset, &length_tool_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->tool_name, length_tool_name);
      offset += length_tool_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_tool_name;
      memcpy(&length_tool_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_tool_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_tool_name-1]=0;
      this->tool_name = (char *)(inbuffer + offset-1);
      offset += length_tool_name;
     return offset;
    }

    const char * getType(){ return PERCEIVECHEMLABTOOL; };
    const char * getMD5(){ return "75b4e63eee5036958205332d0a9fc139"; };

  };

  class PerceiveChemLabToolResponse : public ros::Msg
  {
    public:
      geometry_msgs::TransformStamped tool_pose;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->tool_pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->tool_pose.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return PERCEIVECHEMLABTOOL; };
    const char * getMD5(){ return "b7b88135fc740f90df1e91093d300196"; };

  };

  class PerceiveChemLabTool {
    public:
    typedef PerceiveChemLabToolRequest Request;
    typedef PerceiveChemLabToolResponse Response;
  };

}
#endif
