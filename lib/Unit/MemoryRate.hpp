#pragma once

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class MemoryRate : uint_least8_t {
  BitPerSecond,
  BytePerSecond,
  KilobytePerSecond,
  MegabytePerSecond,
  GigabytePerSecond,
  TerabytePerSecond
};

} // namespace Unit

template <> const std::map<Unit::MemoryRate, std::string> abbreviations<Unit::MemoryRate>{
  {Unit::MemoryRate::BitPerSecond, "b/s"},
  {Unit::MemoryRate::BytePerSecond, "B/s"},
  {Unit::MemoryRate::KilobytePerSecond, "kB/s"},
  {Unit::MemoryRate::MegabytePerSecond, "MB/s"},
  {Unit::MemoryRate::GigabytePerSecond, "GB/s"},
  {Unit::MemoryRate::TerabytePerSecond, "TB/s"}
};

template <> const std::unordered_map<std::string, Unit::MemoryRate> spellings<Unit::MemoryRate>{
  {"b/s", Unit::MemoryRate::BitPerSecond},
  {"B/s", Unit::MemoryRate::BytePerSecond},
  {"kB/s", Unit::MemoryRate::KilobytePerSecond},
  {"MB/s", Unit::MemoryRate::MegabytePerSecond},
  {"GB/s", Unit::MemoryRate::GigabytePerSecond},
  {"TB/s", Unit::MemoryRate::TerabytePerSecond}
};

template <> const std::map<System, Unit::MemoryRate> consistent_units<Unit::MemoryRate>{
  {System::MetreKilogramSecondKelvin, Unit::MemoryRate::BytePerSecond},
  {System::MillimetreGramSecondKelvin, Unit::MemoryRate::BytePerSecond},
  {System::FootPoundSecondRankine, Unit::MemoryRate::BytePerSecond},
  {System::InchPoundSecondRankine, Unit::MemoryRate::BytePerSecond}
};

template <> constexpr const Unit::MemoryRate standard_unit<Unit::MemoryRate>{Unit::MemoryRate::BytePerSecond};

template <> constexpr const Dimension::Set dimension<Unit::MemoryRate>{Dimension::Set{Dimension::Length{}, Dimension::Mass{}, Dimension::Time{-1}}};

template <size_t size> const std::map<Unit::MemoryRate, std::map<Unit::MemoryRate, std::function<void(std::array<double, size>&)>>> conversions<Unit::MemoryRate, size>{
  {Unit::MemoryRate::BitPerSecond, {
    {Unit::MemoryRate::BitPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::MemoryRate::BytePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.125;});}},
    {Unit::MemoryRate::KilobytePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.125 / 1024.0;});}},
    {Unit::MemoryRate::MegabytePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.125 / std::pow(1024.0, 2);});}},
    {Unit::MemoryRate::GigabytePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.125 / std::pow(1024.0, 3);});}},
    {Unit::MemoryRate::TerabytePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.125 / std::pow(1024.0, 4);});}}}},
  {Unit::MemoryRate::BytePerSecond, {
    {Unit::MemoryRate::BitPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 8.0;});}},
    {Unit::MemoryRate::BytePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::MemoryRate::KilobytePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 1024.0;});}},
    {Unit::MemoryRate::MegabytePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= std::pow(1024.0, 2);});}},
    {Unit::MemoryRate::GigabytePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= std::pow(1024.0, 3);});}},
    {Unit::MemoryRate::TerabytePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= std::pow(1024.0, 4);});}}}},
  {Unit::MemoryRate::KilobytePerSecond, {
    {Unit::MemoryRate::BitPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 8.0 * 1024.0;});}},
    {Unit::MemoryRate::BytePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1024.0;});}},
    {Unit::MemoryRate::KilobytePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::MemoryRate::MegabytePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 1024.0;});}},
    {Unit::MemoryRate::GigabytePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= std::pow(1024.0, 2);});}},
    {Unit::MemoryRate::TerabytePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= std::pow(1024.0, 3);});}}}},
  {Unit::MemoryRate::MegabytePerSecond, {
    {Unit::MemoryRate::BitPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 8.0 * std::pow(1024.0, 2);});}},
    {Unit::MemoryRate::BytePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= std::pow(1024.0, 2);});}},
    {Unit::MemoryRate::KilobytePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1024.0;});}},
    {Unit::MemoryRate::MegabytePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::MemoryRate::GigabytePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 1024.0;});}},
    {Unit::MemoryRate::TerabytePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= std::pow(1024.0, 2);});}}}},
  {Unit::MemoryRate::GigabytePerSecond, {
    {Unit::MemoryRate::BitPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 8.0 * std::pow(1024.0, 3);});}},
    {Unit::MemoryRate::BytePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= std::pow(1024.0, 3);});}},
    {Unit::MemoryRate::KilobytePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= std::pow(1024.0, 2);});}},
    {Unit::MemoryRate::MegabytePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1024.0;});}},
    {Unit::MemoryRate::GigabytePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::MemoryRate::TerabytePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 1024.0;});}}}},
  {Unit::MemoryRate::TerabytePerSecond, {
    {Unit::MemoryRate::BitPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 8.0 * std::pow(1024.0, 4);});}},
    {Unit::MemoryRate::BytePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= std::pow(1024.0, 4);});}},
    {Unit::MemoryRate::KilobytePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= std::pow(1024.0, 3);});}},
    {Unit::MemoryRate::MegabytePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= std::pow(1024.0, 2);});}},
    {Unit::MemoryRate::GigabytePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1024.0;});}},
    {Unit::MemoryRate::TerabytePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}}}}
};

} // namespace PhQ
