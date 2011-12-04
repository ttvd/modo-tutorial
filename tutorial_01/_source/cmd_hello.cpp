#include <cmd_hello.h>

#include <lx/lx_io.hpp>
#include <lx/lx_stddialog.hpp>

#include <lx/lx_log.hpp>

namespace ModoTutorial
{
    //--
    CmdHello::CmdHello() :
    CLxBasicCommand()
    {
        
    }   


    //--
    int
    CmdHello::basic_CmdFlags()
    {
        // [rad] This command acts on a model and is undo'able.
        return(LXfCMD_MODEL | LXfCMD_UNDO);
    }


    //--
    void
    CmdHello::cmd_Execute(unsigned int flags)
    {
        // [rad] Log service object.
        CLxUser_LogService service_log;
        
        // [rad] Get a log system corresponding to io-status log subsystem.
        CLxUser_Log log;
        service_log.GetSubSystem("io-status", log);

        // [rad] Print some messages
        log.Message(LXe_WARNING, "This is a warning!");
        log.Message(LXe_INFO, "This is an info!");
        log.Message(LXe_OK, "This is an ok!");
    }


    //--
    void 
    CmdHello::InitializeServerCommand(const char* command_name)
    {
        // [rad] Create generic server object (for our command).
        CLxGenericPolymorph* server_cmd = new CLxPolymorph<CmdHello>();

        // [rad] Add command interface to server object.
        server_cmd->AddInterface(new CLxIfc_Command<CmdHello>);

        // [rad] Register this command server with the framework.
        lx::AddServer(command_name, server_cmd);
    }
}
