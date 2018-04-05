#ifndef QVGRAPHICSVIEW_H
#define QVGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QMimeData>
#include <QDir>

class QVGraphicsView : public QGraphicsView
{

public:
    QVGraphicsView(QWidget *parent = nullptr);

    void loadFile(QString fileName);

    void resetScale();

    void loadMimeData(const QMimeData *mimeData);

    void nextFile();
    void previousFile();

    qreal getCurrentScale() const;
    void setCurrentScale(const qreal &value);

    qreal getScaleFactor() const;
    void setScaleFactor(const qreal &value);

    QGraphicsPixmapItem *getLoadedPixmapItem() const;
    void setLoadedPixmapItem(QGraphicsPixmapItem *value);

    bool getIsCursorEnabled() const;
    void setIsCursorEnabled(bool value);

protected:
    void wheelEvent(QWheelEvent *event) override;

    void resizeEvent(QResizeEvent *event) override;

    void dropEvent(QDropEvent *event) override;

    void dragEnterEvent(QDragEnterEvent *event) override;

    void dragMoveEvent(QDragMoveEvent *event) override;

    void dragLeaveEvent(QDragLeaveEvent *event) override;

    void enterEvent(QEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    qreal currentScale;
    qreal scaleFactor;

    QPixmap loadedPixmap;
    QGraphicsPixmapItem *loadedPixmapItem;
    QTransform fittedMatrix;
    QTransform scaledMatrix;

    bool isPixmapLoaded;
    bool isCursorEnabled;

    QFileInfoList loadedFileFolder;

    int loadedFileFolderIndex;

    const QStringList filterList = (QStringList() << "*.bmp" << "*.gif" << "*.jpg" << "*.jpeg" << "*.png" << "*.pbm" << "*.pgm" << "*.ppm" << "*.xbm" << "*.xpm");
};
#endif // QVGRAPHICSVIEW_H