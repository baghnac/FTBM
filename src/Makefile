###########################################################
# configure gtest lib (the directory name of gtest library)
###########################################################
OS_TYPE				= suse_X86
RM      			= rm -f
RMDIR				= rm -r -f 
MKDIR   			= mkdir -p
COPY				= cp
CC					= gcc

###########################################################
# configure gtest lib (the directory name of gtest library)
###########################################################


ROOT_PATH			= .
EXEC_NAME			= run.exe
MAIN_CODE_PATH		= $(ROOT_PATH)/main
MAIN_CODE_MAKEFILE	= $(MAIN_CODE_PATH)/main.mak
TEST_CODE_PATH		= $(ROOT_PATH)/test
TEST_CODE_MAKEFILE	= $(TEST_CODE_PATH)/test.mak
BUILD_PATH			= $(ROOT_PATH)/../build/$(OS_TYPE)
OBJS_PATH			= $(BUILD_PATH)/Objects
DEPS_PATH			= $(BUILD_PATH)/Depends
RESS_PATH			= $(BUILD_PATH)/Resource

DEPEND_CFLAGS		= -MM
LINK_FLAGS			= -lstdc++ 


.PHONY : clean 
default : $(BUILD_PATH)/$(EXEC_NAME)
	@echo build finish!

include $(MAIN_CODE_MAKEFILE)
#-include $(TEST_CODE_MAKEFILE)

ALL_OBJS += $(OBJS_PATH)/main.o

$(BUILD_PATH)/$(EXEC_NAME):$(ALL_OBJS) $(ALL_RESS)
	@$(MKDIR) $(BUILD_PATH)
	@echo ================== Linking ==================
	@echo $(notdir $(CC)) $(CFLAGS) $(notdir $(ALL_OBJS)) -o $(notdir $@) $(LINK_FLAGS)
	@$(CC) $(CFLAGS) $(ALL_OBJS) -o $@ $(LINK_FLAGS)

$(OBJS_PATH)/main.o : $(BUILD_PATH)/main.c
	@echo making $(notdir $@) ...
	@$(CC) -I$(MAIN_CODE_PATH) -c $< -o $@
	@echo Done!

clean:
	@echo delete $(notdir $(ALL_OBJS) $(ALL_DEPS))
	@$(RM) $(EXEC_NAME) $(ALL_OBJS) $(ALL_DEPS)
	@echo Done!

cleanAll:
	@echo remove dir $(BUILD_PATH)
	@$(RMDIR) $(BUILD_PATH)
	@echo Done!

