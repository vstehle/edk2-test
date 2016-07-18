/*++
  The material contained herein is not a license, either        
  expressly or impliedly, to any intellectual property owned    
  or controlled by any of the authors or developers of this     
  material or to any contribution thereto. The material         
  contained herein is provided on an "AS IS" basis and, to the  
  maximum extent permitted by applicable law, this information  
  is provided AS IS AND WITH ALL FAULTS, and the authors and    
  developers of this material hereby disclaim all other         
  warranties and conditions, either express, implied or         
  statutory, including, but not limited to, any (if any)        
  implied warranties, duties or conditions of merchantability,  
  of fitness for a particular purpose, of accuracy or           
  completeness of responses, of results, of workmanlike         
  effort, of lack of viruses and of lack of negligence, all     
  with regard to this material and any contribution thereto.    
  Designers must not rely on the absence or characteristics of  
  any features or instructions marked "reserved" or             
  "undefined." The Unified EFI Forum, Inc. reserves any         
  features or instructions so marked for future definition and  
  shall have no responsibility whatsoever for conflicts or      
  incompatibilities arising from future changes to them. ALSO,  
  THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT,  
  QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR            
  NON-INFRINGEMENT WITH REGARD TO THE TEST SUITE AND ANY        
  CONTRIBUTION THERETO.                                         
                                                                
  IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THIS MATERIAL OR  
  ANY CONTRIBUTION THERETO BE LIABLE TO ANY OTHER PARTY FOR     
  THE COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST      
  PROFITS, LOSS OF USE, LOSS OF DATA, OR ANY INCIDENTAL,        
  CONSEQUENTIAL, DIRECT, INDIRECT, OR SPECIAL DAMAGES WHETHER   
  UNDER CONTRACT, TORT, WARRANTY, OR OTHERWISE, ARISING IN ANY  
  WAY OUT OF THIS OR ANY OTHER AGREEMENT RELATING TO THIS       
  DOCUMENT, WHETHER OR NOT SUCH PARTY HAD ADVANCE NOTICE OF     
  THE POSSIBILITY OF SUCH DAMAGES.                              
                                                                
  Copyright 2006 - 2016 Unified EFI, Inc. All  
  Rights Reserved, subject to all existing rights in all        
  matters included within this Test Suite, to which United      
  EFI, Inc. makes no claim of right.                            
                                                                
  Copyright (c) 2010 - 2016, Intel Corporation. All rights reserved.<BR>   
   
--*/
/*++

Module Name:

  ComponentName2Protocol.h

Abstract:

  EFI Component Name2 Protocol

--*/

#ifndef _COMPONENT_NAME2_PROTOCOL_H_
#define _COMPONENT_NAME2_PROTOCOL_H_

//
// Global ID for the Component Name Protocol
//
#define EFI_COMPONENT_NAME2_PROTOCOL_GUID    \
  { 0x6a7a5cff, 0xe8d9, 0x4f70, {0xba, 0xda, 0x75, 0xab, 0x30,0x25, 0xce, 0x14 }}

typedef struct _EFI_COMPONENT_NAME2_PROTOCOL EFI_COMPONENT_NAME2_PROTOCOL;;

typedef
EFI_STATUS
(EFIAPI *EFI_COMPONENT_NAME_GET_DRIVER_NAME) (
  IN  EFI_COMPONENT_NAME2_PROTOCOL          *This,
  IN  CHAR8                                 *Language,
  OUT CHAR16                                **DriverName
  );
/*++

  Routine Description:
    Retrieves a Unicode string that is the user readable name of the EFI Driver.

  Arguments:
    This       - A pointer to the EFI_COMPONENT_NAME2_PROTOCOL instance.
    Language   - A pointer to a Null-terminated ASCII string array indicating the
                 language. This is the language of the driver name that the caller
                 is requesting, and it must match one of the languages specified in
                 SupportedLanguages. The number of languages supported by a
                 driver is up to the driver writer. Language is specified in RFC
                 3066 language code format.
    DriverName - A pointer to the Unicode string to return. This Unicode string is
                 the name of the driver specified by This in the language
                 specified by Language.

  Returns:
    EFI_SUCCES            - The Unicode string for the user readable name in the language
                            specified by Language for the driver specified by This was
                            returned in DriverName.
    EFI_INVALID_PARAMETER - Language is NULL.
    EFI_INVALID_PARAMETER - DriverName is NULL.
    EFI_UNSUPPORTED       - The driver specified by This does not support the
                            language specified by Language.

--*/

typedef
EFI_STATUS
(EFIAPI *EFI_COMPONENT_NAME_GET_CONTROLLER_NAME) (
  IN  EFI_COMPONENT_NAME2_PROTOCOL         *This,
  IN  EFI_HANDLE                           ControllerHandle,
  IN  EFI_HANDLE                           ChildHandle        OPTIONAL,
  IN  CHAR8                                *Language,
  OUT CHAR16                               **ControllerName
  );
/*++

  Routine Description:
    Retrieves a Unicode string that is the user readable name of the controller
    that is being managed by an EFI Driver.

  Arguments:
    This             - A pointer to the EFI_COMPONENT_NAME2_PROTOCOL instance.
    ControllerHandle - The handle of a controller that the driver specified by
                       This is managing.  This handle specifies the controller
                       whose name is to be returned.
    ChildHandle      - The handle of the child controller to retrieve the name
                       of.  This is an optional parameter that may be NULL.  It
                       will be NULL for device drivers.  It will also be NULL
                       for bus drivers that attempt to retrieve the name of the
                       bus controller.  It will not be NULL for a bus driver
                       that attempts to retrieve the name of a child controller.
    Language         - A pointer to a Null- terminated ASCII string array indicating the
                       language. This is the language of the controller name that the
                       caller is requesting, and it must match one of the languages
                       specified in SupportedLanguages. The number of languages
                       supported by a driver is up to the driver writer. Language is
                       specified in RFC 3066 language code format.
    ControllerName   - A pointer to the Unicode string to return.  This Unicode
                       string is the name of the controller specified by
                       ControllerHandle and ChildHandle in the language specified
                       by Language from the point of view of the driver specified
                       by This.

  Returns:
    EFI_SUCCESS           - The Unicode string for the user readable name specified by This,
                            ControllerHandle, ChildHandle, and Language was
                            returned in ControllerName.
    EFI_INVALID_PARAMETER - ControllerHandle is not a valid EFI_HANDLE.
    EFI_INVALID_PARAMETER - The driver specified by This is not a device driver, and
                            ChildHandle is not NULL, and ChildHandle is not a
                            valid EFI_HANDLE.
    EFI_INVALID_PARAMETER - Language is NULL.
    EFI_INVALID_PARAMETER - ControllerName is NULL.
    EFI_UNSUPPORTED       - The driver specified by This is not currently managing
                            the controller specified by ControllerHandle and
                            ChildHandle.
    EFI_UNSUPPORTED       - The driver specified by This does not support the
                            language specified by Language.
    EFI_UNSUPPORTED       - The driver specified by This is a device driver and
                            ChildHandle is not NULL.

--*/

//
// Interface structure for the Component Name2 Protocol
//

struct _EFI_COMPONENT_NAME2_PROTOCOL {
  EFI_COMPONENT_NAME_GET_DRIVER_NAME      GetDriverName;
  EFI_COMPONENT_NAME_GET_CONTROLLER_NAME  GetControllerName;
  CHAR8                                   *SupportedLanguages;
};

extern EFI_GUID gBlackBoxEfiComponentName2ProtocolGuid;

#endif

