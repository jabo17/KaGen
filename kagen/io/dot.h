#pragma once

#include <string>

#include <mpi.h>

#include "kagen/io/graph_format.h"

namespace kagen {
class DotWriter : public StandardGraphWriter {
public:
    DotWriter(const bool directed, const OutputGraphConfig& config, Graph& graph, GraphInfo info, PEID rank, PEID size);

protected:
    void WriteHeader(const std::string& filename, SInt n, SInt m) final;

    bool WriteBody(const std::string& filename) final;

    void WriteFooter(const std::string& filename) final;

private:
    bool directed_;
};

class DotFactory : public FileFormatFactory {
public:
    std::string DefaultExtension() const final {
        return "dot";
    }

    std::unique_ptr<GraphWriter>
    CreateWriter(const OutputGraphConfig& config, Graph& graph, GraphInfo info, PEID rank, PEID size) const final;
};

class DirectedDotFactory : public FileFormatFactory {
public:
    std::string DefaultExtension() const final {
        return "dot";
    }

    std::unique_ptr<GraphWriter>
    CreateWriter(const OutputGraphConfig& config, Graph& graph, GraphInfo info, PEID rank, PEID size) const final;
};
} // namespace kagen
