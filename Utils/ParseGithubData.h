#ifndef PARSEGITHUBDATA_H
#define PARSEGITHUBDATA_H

#include <QList>
#include <QString>


class parsegithubData
{
public:
    QList<QPair<QString, QString>> pairs;
    parsegithubData();
    QList<QString> readTrackData();
    void sortDownloadedFiles();
};

#endif  // PARSEGITHUBDATA_H
