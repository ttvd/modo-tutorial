#if !defined(MODOTUTORIAL_TUTORIAL01_INCLUDE_CMD_HELLO_H)
#define MODOTUTORIAL_TUTORIAL01_INCLUDE_CMD_HELLO_H

#include <lx/lxu_command.hpp>

namespace ModoTutorial
{
    class CmdHello : public CLxBasicCommand
    {
        public:

            CmdHello();

        public:

            //! Create an instance of this command server and register it.
            static void InitializeServerCommand(const char* command_name);

        public:

            //! Flags return the type of command.
            int basic_CmdFlags() LXx_OVERRIDE;

            //! Execute this command.
            void cmd_Execute(unsigned int flags) LXx_OVERRIDE;
    };
}

#endif //!defined(MODOTUTORIAL_TUTORIAL01_INCLUDE_CMD_HELLO_H)
