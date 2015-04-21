
include $(MAIN_CODE_PATH)/main_cfg.mak

# service layer
include $(MAIN_SERVICE_MAKEFILE)

# main code application makefile
include $(MAIN_APPLICATION_MAKEFILE)

#  main code domain makefile
include $(MAIN_DOMAIN_MAKEFILE)

# main code infrastructure makefile
include $(MAIN_INFRASTRUCTURE_MAKEFILE)
