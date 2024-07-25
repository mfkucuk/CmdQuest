#pragma once

#ifdef CMDQUEST_EXPORTS
    #define CMDQUEST_API __declspec(dllexport)
#else 
    #define CMDQUEST_API __declspec(dllimport)
#endif