#ifndef _ROS_mln_robosherlock_msgs_MLNAtoms_h
#define _ROS_mln_robosherlock_msgs_MLNAtoms_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace mln_robosherlock_msgs
{

  class MLNAtoms : public ros::Msg
  {
    public:
      const char* mln_atom;
      const char* source;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_mln_atom = strlen(this->mln_atom);
      memcpy(outbuffer + offset, &length_mln_atom, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->mln_atom, length_mln_atom);
      offset += length_mln_atom;
      uint32_t length_source = strlen(this->source);
      memcpy(outbuffer + offset, &length_source, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->source, length_source);
      offset += length_source;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_mln_atom;
      memcpy(&length_mln_atom, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_mln_atom; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_mln_atom-1]=0;
      this->mln_atom = (char *)(inbuffer + offset-1);
      offset += length_mln_atom;
      uint32_t length_source;
      memcpy(&length_source, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_source; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_source-1]=0;
      this->source = (char *)(inbuffer + offset-1);
      offset += length_source;
     return offset;
    }

    const char * getType(){ return "mln_robosherlock_msgs/MLNAtoms"; };
    const char * getMD5(){ return "f2d65da9c776b880a3c56becfafac749"; };

  };

}
#endif