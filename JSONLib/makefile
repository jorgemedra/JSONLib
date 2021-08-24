#------------------------------------------------------------------------------------------------
#
# En este caso se puede compilar como Shared o Dinamic.
#
#https://renenyffenegger.ch/notes/development/languages/C-C-plus-plus/GCC/create-libraries/index
#
#
# Para revisar las dependencias de librerias, utilizar la herramienta otool:
#	$otool -L <executable>
#------------------------------------------------------------------------------------------------

OBJ_DIR 		= ./obj
BIN_DIR 		= ./bin
DBG_DIR 		= ./debug
LIB_DIR			= ./lib
SRC_LIB			= ./src
SRC_SMP			=	./Sample
INC_DIR			= ./include
TARGET_LIB	= libJSONLib.so	#Shared
#TARGET_LIB	= libJSONLib.a 	#Dynamic
TARGET_SMP		= sample

OBJS_LIB		= $(OBJ_DIR)/JSONUnicode.o \
				$(OBJ_DIR)/JSONParser.o \
				$(OBJ_DIR)/JSONParserW.o \
				$(OBJ_DIR)/JSONLib.o \
				$(OBJ_DIR)/JSONLibW.o

OBJS_SMP		= $(OBJ_DIR)/main.o \
				$(OBJ_DIR)/TEST.o \
				$(OBJ_DIR)/TestW.o

OBJS_DBG_SMP	= $(DBG_DIR)/main.o \
				$(DBG_DIR)/TEST.o \
				$(DBG_DIR)/TestW.o	

CPP_SMP			= $(SRC_SMP)/main.cpp \
				$(SRC_SMP)/TEST.cpp \
				$(SRC_SMP)/TestW.cpp	


CC 				= g++
CPPFLAGS 		= -c -g -fPIC -std=c++17 -Wall -MD
CPPFLAGSDEBUG 	= -std=c++17 -w -MD
LIB_MAP			= -Xlinker -Map=$(LIB_DIR)/jsonlib.map
LFLAGS_LIB 		= -shared -lstdc++ $(LIB_MAP)
SMP_MAP			= -Xlinker -Map=$(BIN_DIR)/sample.map
SMP_DBG_MAP	= -Xlinker -Map=$(DBG_DIR)/sample.map
LFLAGS_SMP 		= -lstdc++ -L$(LIB_DIR) -lJSONLib 
FLAG_DEGUB		= -g

build: jsonlib sample

jsonlib: $(OBJS_LIB)
	@mkdir -p $(LIB_DIR)
	# Para Shared
	$(CC) $(LFLAGS_LIB) $(OBJS_LIB) -o $(LIB_DIR)/$(TARGET_LIB)
	#Para Dynamic
	#ar rcs $(BIN_DIR)/$(TARGET_LIB) $(OBJS_LIB)

$(OBJ_DIR)/%.o: $(SRC_LIB)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $< -o $@

-include $(OBJ_DIR)/*.d

sample: $(OBJS_SMP) $(LIB_DIR)/$(TARGET_LIB)
	@echo ***************************************
	@echo "++ buidling [$@]"
	@mkdir -p $(BIN_DIR)
	
	$(CC) $(FLAG_DEGUB) $(OBJS_SMP) -o $(BIN_DIR)/$(TARGET_SMP) $(LFLAGS_SMP) $(SMP_MAP)
	
	
$(OBJ_DIR)/%.o: $(SRC_SMP)/%.cpp $(INC_DIR)/JSONLib.h
	@echo "++ compiling [$@]"
	$(CC) $(CPPFLAGS)  -I$(INC_DIR) $< -o $@
-include $(OBJ_DIR)/*.d

$(INC_DIR)/JSONLib.h:
	@mkdir -p $(INC_DIR)
	cp $(SRC_LIB)/JSONLib.h $(INC_DIR)/JSONLib.h




install: $(LIB_DIR)/$(TARGET_LIB)
	@echo ***************************************
	@echo Installing /usr/lib/$(TARGET_LIB)
	
	cp -f $(LIB_DIR)/$(TARGET_LIB) /usr/lib
	chmod 0755 /usr/lib/$(TARGET_LIB)
	ldconfig
	@echo checking instalation
	ldconfig -p | grep $(TARGET_LIB)


uninstall: /usr/lib/$(TARGET_LIB)
	@echo ***************************************
	@echo Uninstalling /usr/lib/$(TARGET_LIB)
	rm -f /usr/lib/$(TARGET_LIB)
	@ldconfig

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(BIN_DIR)
	rm -rf $(LIB_DIR)
	rm -rf $(INC_DIR)
	rm -rf $(DBG_DIR)

cdebug:
	rm -rf $(DBG_DIR)