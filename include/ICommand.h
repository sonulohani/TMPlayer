/*
 * Copyright (C) 2020-present, Sonu Lohani & tmplayer contributors.
 * Please read the license file provided with the tool or click on
 * this link : https://github.com/sonulohani/tmplayer/blob/master/LICENSE
 */

#pragma once

#include <QVariant>

namespace tmplayer
{
class ICommand
{
  public:
    virtual ~ICommand() = default;
    virtual void execute(const QVariant &) = 0;
};
} // namespace tmplayer
