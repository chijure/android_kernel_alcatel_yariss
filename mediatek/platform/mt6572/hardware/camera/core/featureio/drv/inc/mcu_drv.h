

#ifndef _MCU_DRV_H_
#define _MCU_DRV_H_

#include "MediaTypes.h"
#include "camera_custom_lens.h"              //in custom folder 

//Structures
typedef struct {
    //current position
    unsigned long u4CurrentPosition;
    //macro position
    unsigned long u4MacroPosition;
    //Infiniti position
    unsigned long u4InfPosition;
    //Motor Status
    bool          bIsMotorMoving;
    //Motor Open?
    bool          bIsMotorOpen;
    //Slew Rate?
    bool          bIsSupportSR;
    
} mcuMotorInfo;


class MCUDrv {
public:
    /////////////////////////////////////////////////////////////////////////
    //
    /////////////////////////////////////////////////////////////////////////                           
    typedef enum
    {
        MCU_NO_ERROR = 0,                  ///< The function work successfully
        MCU_UNKNOWN_ERROR = 0x80000000,    ///< Unknown error    
        MCU_INVALID_DRIVER   = 0x80000001,
    } MCU_ERROR_ENUM;

protected:
    /////////////////////////////////////////////////////////////////////////
    //
    // ~MCUDrv () -
    //! \brief mhal mcu base descontrustor
    //
    /////////////////////////////////////////////////////////////////////////    
    virtual ~MCUDrv() = 0;

public:     //// Interfaces
    /////////////////////////////////////////////////////////////////////////
    //
    /////////////////////////////////////////////////////////////////////////                           
    static MCUDrv* createInstance(unsigned int a_u4CurrLensId);

    /////////////////////////////////////////////////////////////////////////
    //
    /////////////////////////////////////////////////////////////////////////                           
    virtual void destroyInstance() = 0;

    /////////////////////////////////////////////////////////////////////////
    //
    // init () -
    //! \brief 
    //
    /////////////////////////////////////////////////////////////////////////    
    virtual int init() = 0; 

    /////////////////////////////////////////////////////////////////////////
    //
    // uninit () -
    //! \brief 
    //
    /////////////////////////////////////////////////////////////////////////    
    virtual int uninit() = 0;

    /////////////////////////////////////////////////////////////////////////
    //
    // moveMCU () -
    //! \brief 
    //
    /////////////////////////////////////////////////////////////////////////    
    virtual int moveMCU(int a_i4FocusPos) = 0;

    /////////////////////////////////////////////////////////////////////////
    //
    // getMCUInfo () -
    //! \brief 
    //
    /////////////////////////////////////////////////////////////////////////    
    virtual int  getMCUInfo(mcuMotorInfo *a_pMotorInfo) = 0;

    /////////////////////////////////////////////////////////////////////////
    //
    // setMCUInfPos () -
    //! \brief 
    //
    /////////////////////////////////////////////////////////////////////////    
    virtual int setMCUInfPos(int a_i4FocusPos) = 0;

    /////////////////////////////////////////////////////////////////////////
    //
    // setMCUMacroPos () -
    //! \brief 
    //
    /////////////////////////////////////////////////////////////////////////    
    virtual int setMCUMacroPos(int a_i4FocusPos) = 0;

    /////////////////////////////////////////////////////////////////////////
    //
    // lensSearch () -
    //! \brief 
    //
    /////////////////////////////////////////////////////////////////////////   
    static int lensSearch(unsigned int  a_u4CurrSensorDev, unsigned int  a_u4CurrSensorId);

    /////////////////////////////////////////////////////////////////////////
    //
    // getCurrLensID () -
    //! \brief 
    //
    /////////////////////////////////////////////////////////////////////////   
    static unsigned int getCurrLensID();

    //FIXME, is this need here 
    static MSDK_LENS_INIT_FUNCTION_STRUCT m_LensInitFunc[MAX_NUM_OF_SUPPORT_LENS];
    static unsigned int  m_u4CurrLensIdx;

};

#endif

