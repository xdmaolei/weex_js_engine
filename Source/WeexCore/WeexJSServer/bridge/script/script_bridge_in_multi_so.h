//
// Created by yxp on 2018/6/15.
//

#ifndef WEEXV8_MULTI_SO_JS_BRIDGE_H
#define WEEXV8_MULTI_SO_JS_BRIDGE_H

#include "core/bridge/script_bridge.h"

namespace weex {
namespace bridge {
namespace js {
class ScriptBridgeInMultiSo : public WeexCore::ScriptBridge {
 public:
  static FunctionsExposedByJS *GetExposedFunctions();

  static int InitFramework(const char *script,
                           std::vector<INIT_FRAMEWORK_PARAMS *> params);

  static int InitAppFramework(const char *instanceId, const char *appFramework,
                              std::vector<INIT_FRAMEWORK_PARAMS *> params);

  static int CreateAppContext(const char *instanceId, const char *jsBundle);

  static char *ExecJSOnAppWithResult(const char *instanceId,
                                     const char *jsBundle);

  static int CallJSOnAppContext(const char *instanceId, const char *func,
                                std::vector<VALUE_WITH_TYPE *> params);

  static int DestroyAppContext(const char *instanceId);

  static int ExecJSService(const char *source);

  static int ExecTimeCallback(const char *source);

  static int ExecJS(const char *instanceId, const char *nameSpace,
                    const char *func, std::vector<VALUE_WITH_TYPE *> params);

  static WeexJSResult ExecJSWithResult(const char *instanceId,
                                       const char *nameSpace, const char *func,
                                       std::vector<VALUE_WITH_TYPE *> params);

  static int CreateInstance(const char *instanceId, const char *func,
                            const char *script, const char *opts,
                            const char *initData, const char *extendsApi);

  static char *ExecJSOnInstance(const char *instanceId, const char *script);

  static int DestroyInstance(const char *instanceId);

  static int UpdateGlobalConfig(const char *config);

 private:
  static ScriptBridgeInMultiSo *g_instance;
  static ScriptBridgeInMultiSo *Instance() {
    if (g_instance == NULL) {
      g_instance = new ScriptBridgeInMultiSo();
    }
    return g_instance;
  }

  ScriptBridgeInMultiSo();
  virtual ~ScriptBridgeInMultiSo();
  DISALLOW_COPY_AND_ASSIGN(ScriptBridgeInMultiSo);
};
}  // namespace js
}  // namespace bridge
}  // namespace weex

#endif  // WEEXV8_MULTI_SO_JS_BRIDGE_H