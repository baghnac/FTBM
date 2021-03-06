
TEST_APPLICATION_FILE_EXTENTION	= cpp
TEST_APPLICATION_SRC_PATH     	= $(TEST_APPLICATION_PATH)/source
TEST_APPLICATION_RES_SRC_PATH	= $(TEST_APPLICATION_PATH)/resource
TEST_APPLICATION_INCLUDE_PATH 	= $(TEST_PUB_INCLUDE_PATH) $(APPLICATION_INCLUDE_PATH)
TEST_APPLICATION_OBJS_PATH    	= $(TEST_OBJS_PATH)/APPLICATION
TEST_APPLICATION_DEPS_PATH		= $(TEST_DEPS_PATH)/APPLICATION
TEST_APPLICATION_RES_BUILD_PATH	= $(TEST_RESS_PATH)/APPLICATION
TEST_APPLICATION_CFLAGS			= $(TEST_CODE_CFLAGS) -DRESOURCE_PATH=\"Resource/TEST/APPLICATION/\"
TEST_APPLICATION_DEPEND_CFLAGS	= $(TEST_DEPEND_CFLAGS)

TEST_APPLICATION_INCLUDE = $(addprefix -I, $(TEST_APPLICATION_INCLUDE_PATH))
TEST_APPLICATION_SRCS	= $(wildcard $(TEST_APPLICATION_SRC_PATH)/*.$(TEST_APPLICATION_FILE_EXTENTION))
TEST_APPLICATION_OBJS	= $(addprefix $(TEST_APPLICATION_OBJS_PATH)/,$(notdir $(subst .$(TEST_APPLICATION_FILE_EXTENTION),.o,$(TEST_APPLICATION_SRCS))))
TEST_APPLICATION_DEPS	= $(addprefix $(TEST_APPLICATION_DEPS_PATH)/,$(notdir $(subst .$(TEST_APPLICATION_FILE_EXTENTION),.d,$(TEST_APPLICATION_SRCS))))
TEST_APPLICATION_SRC_RES	= $(wildcard $(TEST_APPLICATION_RES_SRC_PATH)/*)
TEST_APPLICATION_RESS	= $(addprefix $(TEST_APPLICATION_RES_BUILD_PATH)/,$(notdir $(TEST_APPLICATION_SRC_RES)))
ALL_OBJS 	 += $(TEST_APPLICATION_OBJS)
ALL_DEPS	 += $(TEST_APPLICATION_DEPS)
ALL_RESS	 += $(TEST_APPLICATION_RESS)

$(TEST_APPLICATION_RES_BUILD_PATH)/% : $(TEST_APPLICATION_RES_SRC_PATH)/%
	@$(MKDIR) $(TEST_APPLICATION_RES_BUILD_PATH)
	@echo copy APPLICATION resource:$(notdir $<)
	@$(COPY) $< $@
	@echo Done!

$(TEST_APPLICATION_DEPS_PATH)/%.d : $(TEST_APPLICATION_SRC_PATH)/%.$(TEST_APPLICATION_FILE_EXTENTION)
	@$(MKDIR) $(TEST_APPLICATION_DEPS_PATH)
	@echo Making $(notdir $@) ...
	@$(CC) $(TEST_APPLICATION_DEPEND_CFLAGS) $(TEST_APPLICATION_INCLUDE) $< | sed 's/$*.o:/$(subst /,\/,$(TEST_APPLICATION_OBJS_PATH))\/$*.o:/g' > $@
	@echo Done!

-include $(TEST_APPLICATION_DEPS)

$(TEST_APPLICATION_OBJS_PATH)/%.o : $(TEST_APPLICATION_SRC_PATH)/%.$(TEST_APPLICATION_FILE_EXTENTION)
	@$(MKDIR) $(TEST_APPLICATION_OBJS_PATH)
	@echo Making $(notdir $@) ...
	@$(CC) $(TEST_APPLICATION_CFLAGS) $(TEST_APPLICATION_INCLUDE) $< -c -o $@
	@echo Done!


