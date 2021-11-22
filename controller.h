#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "imodel.h"
#include "icontroller.h"

/**
 * @brief Класс Controller (MVC)
 */
class Controller : public IController
{
public:
    /**
     * @brief Controller (MVC)
     * @param model - указатель на модель (MVC)
     */
    Controller(IModel *model) : m_model(model) {}

    /**
     * @brief Создание нового документа
     */
    void createNew() override
    {
        m_model->createNew();
    }

    /**
     * @brief Импорт документа из файла
     * @param[in] filename - имя файла
     */
    void importFromFile(const std::string &filename) override
    {
        m_model->importFromFile(filename);
    }

    /**
     * @brief Экспорт документа в файл
     * @param[in] filename - имя файла
     */
    void exportToFile(const std::string &filename) override
    {
        m_model->exportToFile(filename);
    }

    /**
     * @brief Добавление прямоугольника
     * @param[in] rectangle - указатель на прямоугольник
     */
    void addRectangle(Rectangle *rectangle) override
    {
        m_model->addPrimitive(rectangle);
    }

    /**
     * @brief Добавление эллипса
     * @param[in] ellipse - указатель на эллипс
     */
    void addEllipse(Ellipse *ellipse) override
    {
        m_model->addPrimitive(ellipse);
    }

    /**
     * @brief Добавление треугольника
     * @param[in] triangle - указатель на треугольник
     */
    void addTriangle(Triangle *triangle) override
    {
        m_model->addPrimitive(triangle);
    }

    /**
     * @brief Удаление графического примитива
     * @param[in] primitive - указатель на удаляемый графический примитив
     */
    void removePrimitive(IPrimitive *primitive) override
    {
        m_model->removePrimitive(primitive);
    }

    /**
     * @brief Выбор текущего примитива по индексу
     * @param[in] index - индекс
     */
    void selectPrimitive(int index) override
    {
        m_model->selectPrimitive(index);
    }

private:
    IModel *m_model;
};

#endif // CONTROLLER_H
