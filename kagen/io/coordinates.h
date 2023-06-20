#pragma once

#include <string>

#include <mpi.h>

#include "kagen/io/graph_format.h"

namespace kagen {
class CoordinatesWriter : public StandardGraphWriter {
public:
    CoordinatesWriter(const OutputGraphConfig& config, Graph& graph, GraphInfo info, PEID rank, PEID size);

protected:
    void WriteHeader(const std::string& filename, const SInt n, const SInt m) final;

    bool WriteBody(const std::string& filename) final;
};

class CoordinatesFactory : public FileFormatFactory {
public:
    std::string DefaultExtension() const final {
        return "xyz";
    }

    std::unique_ptr<GraphWriter>
    CreateWriter(const OutputGraphConfig& config, Graph& graph, GraphInfo info, PEID rank, PEID size) const final;
};
} // namespace kagen
