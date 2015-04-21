
TEST_INFRASTRUCTURE_FILE_EXTENTION	= cpp
TEST_INFRASTRUCTURE_SRC_PATH     	= $(TEST_INFRASTRUCTURE_PATH)/source
TEST_INFRASTRUCTURE_RES_SRC_PATH	= $(TEST_INFRASTRUCTURE_PATH)/resource
TEST_INFRASTRUCTURE_INCLUDE_PATH 	= $(TEST_PUB_INCLUDE_PATH) $(INFRASTRUCTURE_INCLUDE_PATH)
TEST_INFRASTRUCTURE_OBJS_PATH    	= $(TEST_OBJS_PATH)/INFRASTRUCTURE
TEST_INFRASTRUCTURE_DEPS_PATH		= $(TEST_DEPS_PATH)/INFRASTRUCTURE
TEST_INFRASTRUCTURE_RES_BUILD_PATH	= $(TEST_RESS_PATH)/INFRASTRUCTURE
TEST_INFRASTRUCTURE_CFLAGS			= $(TEST_CODE_CFLAGS) -DRESOURCE_PATH=\"Resource/TEST/INFRASTRUCTURE/\"
TEST_INFRASTRUCTURE_DEPEND_CFLAGS	= $(TEST_DEPEND_CFLAGS)

TEST_INFRASTRUCTURE_INCLUDE = $(addprefix -I, $(TEST_INFRASTRUCTURE_INCLUDE_PATH))
TEST_INFRASTRUCTURE_SRCS	= $(wildcard $(TEST_INFRASTRUCTURE_SRC_PATH)/*.$(TEST_INFRASTRUCTURE_FILE_EXTENTION))
TEST_INFRASTRUCTURE_OBJS	= $(addprefix $(TEST_INFRASTRUCTURE_OBJS_PATH)/,$(notdir $(subst .$(TEST_INFRASTRUCTURE_FILE_EXTENTION),.o,$(TEST_INFRASTRUCTURE_SRCS))))
TEST_INFRASTRUCTURE_DEPS	= $(addprefix $(TEST_INFRASTRUCTURE_DEPS_PATH)/,$(notdir $(subst .$(TEST_INFRASTRUCTURE_FILE_EXTENTION),.d,$(TEST_INFRASTRUCTURE_SRCS))))
TEST_INFRASTRUCTURE_SRC_RES	= $(wildcard $(TEST_INFRASTRUCTURE_RES_SRC_PATH)/*)
TEST_INFRASTRUCTURE_RESS	= $(addprefix $(TEST_INFRASTRUCTURE_RES_BUILD_PATH)/,$(notdir $(TEST_INFRASTRUCTURE_SRC_RES)))
ALL_OBJS 	 += $(TEST_INFRASTRUCTURE_OBJS)
ALL_DEPS	 += $(TEST_INFRASTRUCTURE_DEPS)
ALL_RESS	 += $(TEST_INFRASTRUCTURE_RESS)

$(TEST_INFRASTRUCTURE_RES_BUILD_PATH)/% : $(TEST_INFRASTRUCTURE_RES_SRC_PATH)/%
	@$(MKDIR) $(TEST_INFRASTRUCTURE_RES_BUILD_PATH)
	@echo copy INFRASTRUCTURE resource:$(notdir $<)
	@$(COPY) $< $@
	@echo Done!

$(TEST_INFRASTRUCTURE_DEPS_PATH)/%.d : $(TEST_INFRASTRUCTURE_SRC_PATH)/%.$(TEST_INFRASTRUCTURE_FILE_EXTENTION)
	@$(MKDIR) $(TEST_INFRASTRUCTURE_DEPS_PATH)
	@echo Making $(notdir $@) ...
	@$(CC) $(TEST_INFRASTRUCTURE_DEPEND_CFLAGS) $(TEST_INFRASTRUCTURE_INCLUDE) $< | sed 's/$*.o:/$(subst /,\/,$(TEST_INFRASTRUCTURE_OBJS_PATH))\/$*.o:/g' > $@
	@echo Done!

-include $(TEST_INFRASTRUCTURE_DEPS)

$(TEST_INFRASTRUCTURE_OBJS_PATH)/%.o : $(TEST_INFRASTRUCTURE_SRC_PATH)/%.$(TEST_INFRASTRUCTURE_FILE_EXTENTION)
	@$(MKDIR) $(TEST_INFRASTRUCTURE_OBJS_PATH)
	@echo Making $(notdir $@) ...
	@$(CC) $(TEST_INFRASTRUCTURE_CFLAGS) $(TEST_INFRASTRUCTURE_INCLUDE) $< -c -o $@
	@echo Done!


