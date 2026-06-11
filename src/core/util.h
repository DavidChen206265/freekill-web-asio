// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

std::string calcFileMD5();

// Web-only fork(W0-2):枚举服务端实际启用的包(供 Web manifest)。
// 含 builtins(standard/standard_cards/maneuvering),加 packages/ 顶层
// 非 .disabled、未 disabled、含 init.lua 的扩展包。与 writePkgsMD5 同源扫描,
// 但 writePkgsMD5 为算 flist md5 而排除 builtins,这里相反:UI 要完整启用集。
std::vector<std::string> listEnabledPacks();

namespace fkShell {
  enum TextColor {
    Black,
    Red,
    Green,
    Yellow,
    Blue,
    Magenta,
    Cyan,
  };
  enum TextType {
    NoType,
    Bold,
    UnderLine
  };
}

std::string Color(const std::string &raw, fkShell::TextColor color,
                                  fkShell::TextType type = fkShell::NoType);

std::string toHex(std::string_view sv);

std::string qCompress_std(const std::string_view &data, int level = -1);
std::string qUncompress_std(const std::string_view &data);
