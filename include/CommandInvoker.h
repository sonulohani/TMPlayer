/*
 * Copyright (C) 2020-present, Sonu Lohani & tmplayer contributors.
 * Please read the license file provided with the tool or click on
 * this link : https://github.com/sonulohani/tmplayer/blob/master/LICENSE
 */

#pragma once

#include "ICommand.h"

#include <QHash>
#include <QHashFunctions>
#include <QSharedPointer>
#include <cstdint>

namespace tmplayer
{
class CommandInvoker
{
  public:
    enum class CommandType : int8_t
    {
        PLAY = 0,
        PAUSE = 1,
        NONE = -1
    };

  public:
    CommandInvoker() = default;
    virtual ~CommandInvoker() = default;
    void registerCommand(const CommandInvoker::CommandType type, const QSharedPointer<ICommand> &commandSPtr);
    bool invoke(const QString &commandStr, QSharedPointer<ICommand> &commandSPtr);

  private:
    static const QHash<QString, CommandType> s_kCommandMap;
    QHash<CommandType, QSharedPointer<ICommand>> m_typeToCommandMap;
};

inline uint qHash(const CommandInvoker::CommandType &key)
{
    return qHash(QString::number(static_cast<uint>(key)));
}

} // namespace tmplayer