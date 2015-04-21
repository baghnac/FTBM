include $(TEST_CODE_PATH)/test_cfg.mak

# service layer
include $(TEST_SERVICE_MAKEFILE)

# main code application makefile
include $(TEST_APPLICATION_MAKEFILE)

#  main code domain makefile
include $(TEST_DOMAIN_MAKEFILE)

# main code infrastructure makefile
include $(TEST_INFRASTRUCTURE_MAKEFILE)

